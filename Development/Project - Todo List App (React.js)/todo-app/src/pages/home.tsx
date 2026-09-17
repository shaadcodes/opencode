import React from "react";
import { useState, useEffect } from "react";
import TaskCard from "../components/taskCard";
import Switch from "../components/switch";
// import LoadingSpinner from "../components/loadingSpinner";
import LoadingSkeleton from "../components/loadingSkeleton";
import EmptyState from "../components/emptyState";
import { FiCheck, FiPlus } from "react-icons/fi";

interface todoItem {
  _id: string;
  text: string;
  completed: boolean;
}

const Home: React.FC<{}> = () => {
  const [todos, settodos] = useState<todoItem[]>([]);
  const [input, setinput] = useState(``);
  const [editId, seteditId] = useState<string | null>(null);
  const [loading, setloading] = useState(true);
  const [showCompleted, setshowCompleted] = useState<boolean>(false);
  const fetchURL = import.meta.env.VITE_API_URL || "https://shaad-todo-api.vercel.app//api/todos";

  useEffect(() => {
    fetch(fetchURL)
      .then((res) => res.json())
      .then((data) => {
        settodos(data);
        setloading(false);
      })
      .catch((error) => {
        console.error(`Error fetching tasks!: `, error);
        setloading(false);
      });
  }, []);

  const displayedTasks = showCompleted
    ? todos.map((todo) => todo)
    : todos.filter((todo) => !todo.completed);

  const toggleComplete = async (id: string, completed: boolean) => {
    const res = await fetch(`${fetchURL}/${id}`, {
      method: "PUT",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ completed: !completed }),
    });

    const updated = await res.json();
    settodos(todos.map((todo) => (todo._id === id ? updated : todo)));
  };

  const editTask = async (id: string, currentText: string) => {
    seteditId(id);
    setinput(currentText);
  };

  const saveTask = async () => {
    if (!input.trim()) return;
    if (editId) {
      const res = await fetch(`${fetchURL}/${editId}`, {
        method: "PUT",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ text: input }),
      });

      const updated = await res.json();
      settodos(todos.map((todo) => (todo._id === editId ? updated : todo)));
      seteditId(null);
    } else {
      const res = await fetch(fetchURL, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ text: input }),
      });

      const data = await res.json();
      settodos([data, ...todos]);
    }

    setinput(``);
  };

  const deleteTask = async (id: string) => {
    const isConfirmed = window.confirm(
      "Are you sure you want to delete this task?",
    );
    if (isConfirmed) {
      alert("Task Deleted!");
      await fetch(`${fetchURL}/${id}`, { method: "DELETE" });
      settodos(todos.filter((todo) => todo._id !== id));
    }
  };

  return (
    <section
      className="
          max-w-xl
          mx-auto p-8
          bg-white/80
          rounded-3xl border border-white/60
          shadow-xl shadow-slate-200/80 transition-colors
          dark:bg-zinc-900/80 backdrop-blur-md dark:border-zinc-800 dark:shadow-zinc-900/60
        "
    >
      <div
        className="
            flex
            pb-6 max-sm:pb-3 max-sm:gap-2
            border-b border-slate-100
            addTask items-center justify-between dark:border-zinc-800
          "
      >
        <h1
          className="
              text-2xl font-bold text-slate-800
              dark:text-zinc-200 max-sm:text-xl
            "
        >
          My Tasks
        </h1>
        <p
          className="
              mt-0.5
              text-sm text-slate-500
              dark:text-zinc-500 max-sm:text-xs
            "
        >
          <p>
            {todos.filter((todo) => !todo.completed).length} pending,{" "}
            {todos.filter((todo) => todo.completed).length} completed
          </p>
        </p>
      </div>
      <div
        className="
            flex
            mt-6 max-sm:mt-3
            showCompleted gap-2 items-center
          "
      >
        <span
          className="
              text-xs font-semibold text-slate-500 tracking-wider
              uppercase
            "
        >
          Completed
        </span>
        <Switch
          condition={showCompleted}
          setCondition={setshowCompleted}
          activebg="bg-blue-600 dark:bg-blue-900"
          inactivebg="bg-slate-200 dark:bg-slate-800"
          knob="bg-white dark:bg-zinc-400"
        />
      </div>
      <div
        className="
            flex
            mt-6 p-1.5
            bg-slate-50
            border border-slate-200/80 rounded-2xl max-sm:rounded-full max-sm:px-2
            inputBar items-center gap-2 max-sm:gap-0 focus-within:ring-2 focus-within:ring-blue-500/20 focus-within:border-blue-500 transition dark:bg-zinc-800 dark:border-zinc-600/20 dark:focus-within:ring-blue-950/40 dark:focus-within:border-blue-950
          "
      >
        <input
          type="text"
          value={input}
          onChange={(e) => setinput(e.target.value)}
          onKeyDown={(e) => e.key === `Enter` && saveTask()}
          placeholder="Record a task..."
          className="
              px-3 py-2 min-w-10
              text-slate-800 placeholder-slate-400 text-sm
              bg-transparent
              grow dark:text-zinc-100 dark:placeholder-zinc-500 focus:outline-none
            "
        />
        <button
          onClick={saveTask}
          className={`
              flex
              px-4 py-2
              text-white text-sm font-semibold
              bg-blue-600
              rounded-xl
              shadow-sm
              hover:bg-blue-700 active:scale-95 transition gap-2 dark:bg-blue-900 dark:text-zinc-300 dark:hover:bg-zinc-700 max-sm:text-xs
              ${editId ? `bg-green-600 active:bg-green-700 dark:bg-green-900 dark:active:bg-green-950` : ``} max-sm:hidden
            `}
        >
          {editId ? "Update task" : <p>+ Add</p>}
        </button>
        <button
          onClick={saveTask}
          className={`
              flex items-center justify-center
              text-white text-sm font-medium
              bg-blue-600
              rounded-full size-8 min-h-8 min-w-8
              shadow-sm
              hover:bg-blue-700 active:scale-95 transition gap-2 dark:bg-blue-900 dark:text-zinc-300 dark:hover:bg-zinc-700 max-sm:text-xs
              ${editId ? `bg-green-600 active:bg-green-700 dark:bg-green-900 dark:active:bg-green-950` : ``} sm:hidden
            `}
        >
          {editId ? (
            <FiCheck className="size-4 text-emerald-500" />
          ) : (
            <FiPlus className="size-4 text-slate-100" />
          )}
        </button>
      </div>
      <div
        className={`
            mt-6 space-y-2
          `}
      >
        {loading ? (
          <div
            className="
                flex
                my-auto
                loadWrapper items-center justify-center
              "
          >
            <LoadingSkeleton />
          </div>
        ) : displayedTasks.length === 0 ? (
          <div>
            <EmptyState onFocusInput={() => document.querySelector('input')?.focus()}/>
          </div>
        ) : (
          displayedTasks.map((todo) => (
            <TaskCard
              key={todo._id}
              id={todo._id}
              text={todo.text}
              completed={todo.completed}
              onToggle={toggleComplete}
              onEdit={editTask}
              onDelete={deleteTask}
            />
          ))
        )}
      </div>
    </section>
  );
};

export default Home;
