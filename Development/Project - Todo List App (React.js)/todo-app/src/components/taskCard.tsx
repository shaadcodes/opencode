import React from "react";
import { FiEdit3, FiTrash2 } from "react-icons/fi";

interface TaskCardProps {
  key: string;
  id: string;
  text: string;
  completed: boolean;
  onToggle: (id: string, completed: boolean) => void;
  onEdit: (id: string, text: string) => void;
  onDelete: (id: string) => void;
}

const TaskCard: React.FC<TaskCardProps> = ({
  id,
  text,
  completed,
  onToggle,
  onEdit,
  onDelete,
}) => {
  return (
    <>
      <div
        id={id}
        className="group flex items-center justify-between p-3.5 bg-white rounded-xl border border-slate-100 hover:border-blue-100 hover:shadow-2xs dark:bg-zinc-800 dark:border-slate-900 dark:hover:border-slate-700 transition"
      >
        <div className="taskLeft flex items-center gap-3">
          <input
            type="checkbox"
            checked={completed}
            onChange={() => onToggle(id, completed)}
            className="size-4 rounded border-slate-300 text-blue-600 focus:ring-blue-500 cursor-pointer checked:bg-zinc-700"
          />
          <h1
            className={`text-sm max-[600px]:text-xs ${completed ? `line-through text-slate-400 italic` : `text-slate-700 dark:text-slate-200`}`}
          >
            {text}
          </h1>
        </div>
        <div className="flex items-center gap-1 opacity-0 max-sm:opacity-100 group-hover:opacity-100 transition-opacity">
          <button
            onClick={() => onEdit(id, text)}
            className="edit p-1.5 text-slate-400 hover:text-blue-600 rounded-md hover:bg-slate-50 cursor-pointer dark:hover:bg-slate-700"
          >
            <FiEdit3 />
          </button>
          <button
            onClick={() => onDelete(id)}
            className="delete p-1.5 text-slate-400 hover:text-red-600 rounded-md hover:bg-red-50 dark:hover:bg-red-900"
          >
            <FiTrash2 />
          </button>
        </div>
      </div>
    </>
  );
};

export default TaskCard;
