import { useState, useEffect, useRef } from "react";
import { BrowserRouter, Routes, Route, Link } from "react-router-dom";
import { FiCheckSquare, FiHome, FiInfo, FiNavigation } from "react-icons/fi";
import { RiDropdownList } from "react-icons/ri";
import { MdOutlineDarkMode, MdOutlineClose } from "react-icons/md";
import { CiLight } from "react-icons/ci";
import Home from "./pages/home";
import About from "./pages/about";
import Contact from "./pages/contact";
import Switch from "./components/switch";

function App() {
  const [toggleSidebar, setToggleSidebar] = useState<boolean>(false);
  const sideBarRef = useRef<HTMLDivElement>(null);

  const [darkTheme, setDarkTheme] = useState<boolean>(() => {
    return (
      localStorage.getItem("theme") === "dark" ||
      (!("theme" in localStorage) &&
        window.matchMedia("(prefers-color-scheme: dark)").matches)
    );
  });

  useEffect(() => {
    const root = document.documentElement;
    if (darkTheme) {
      root.classList.add("dark");
      localStorage.setItem("theme", "dark");
    } else {
      root.classList.remove("dark");
      localStorage.setItem("theme", "light");
    }
  }, [darkTheme]);

  useEffect(() => {
    if(!toggleSidebar) return;

    const handleOutsideClick = (e: MouseEvent) => {
      if(sideBarRef.current && !sideBarRef.current.contains(e.target as Node))
      {
        setToggleSidebar(false);
      }
    };

    const handleScroll = () => {
      setToggleSidebar(false);
    }

    document.addEventListener("mousedown", handleOutsideClick);
    window.addEventListener("scroll", handleScroll, {passive: true});

    return () => {
      document.removeEventListener("mousedown", handleOutsideClick);
      window.removeEventListener("scroll", handleScroll);
    };
  }, [toggleSidebar]);
  

  return (
    <BrowserRouter>
      <nav
        className="
          flex z-50
          h-24
          p-6
          text-slate-100
          bg-blue-800
          border-b border-b-white/60
          shadow-xl shadow-slate-200/80 transition-colors
          justify-between items-center dark:bg-zinc-950/95 backdrop-blur-md dark:border-zinc-800 dark:shadow-zinc-900/60 relative
        "
      >
        <div
          className="
            flex
            max-sm:gap-2
            cursor-pointer
            left items-center gap-4
          "
        >
          <FiCheckSquare
            className="
              max-sm:size-6
              size-8
            "
          />
          <Link
            to="/"
            className="
              max-sm:text-xl
              text-3xl font-extrabold
            "
          >
            To-do List App
          </Link>
        </div>
        <button
          className="
            hamburger sm:hidden
          "
          onClick={() => setToggleSidebar(!toggleSidebar)}
        >
          {toggleSidebar ? (
            <MdOutlineClose className="size-6"/>
          ) : (
            <RiDropdownList className="size-6"/>
          )}
        </button>
        <div
          className="
            flex gap-6 max-sm:hidden
          "
        >
          <Link
            to="/"
            className="
              flex
              max-sm:gap-1
              rounded-sm
              cursor-pointer
              hover:px-4 hover:py-2 home group gap-2 items-center hover:bg-blue-50 dark:hover:bg-zinc-800 hover:text-blue-600 dark:hover:text-slate-400
            "
          >
            <FiHome
              className="
                max-sm:size-4
                size-5 shrink-0
              "
            />
            <p
              className="
                overflow-hidden
                max-w-0 max-sm:text-xs
                font-bold whitespace-nowrap
                opacity-0 transition-all
                -translate-x-8 group-hover:max-w-xs group-hover:opacity-100 group-hover:ml-2 group-hover:translate-x-0 duration-300
              "
            >
              Home
            </p>
          </Link>
          <Link
            to="/about"
            className="
              flex
              max-sm:gap-1
              rounded-sm
              cursor-pointer
              hover:px-4 hover:py-2 about group gap-2 items-center hover:bg-blue-50 dark:hover:bg-zinc-800 hover:text-blue-600 dark:hover:text-slate-400
            "
          >
            <FiInfo
              className="
                max-sm:size-4
                size-5 shrink-0
              "
            />
            <p
              className="
                overflow-hidden
                max-w-0 max-sm:text-xs
                font-bold whitespace-nowrap
                opacity-0 transition-all
                -translate-x-8 group-hover:max-w-xs group-hover:opacity-100 group-hover:ml-2 group-hover:translate-x-0 duration-300
              "
            >
              About
            </p>
          </Link>
          <Link
            to="/contact"
            className="
              flex
              max-sm:gap-1
              rounded-sm
              cursor-pointer
              hover:px-4 hover:py-2 contact group gap-2 items-center hover:bg-blue-50 dark:hover:bg-zinc-800 hover:text-blue-600 dark:hover:text-slate-400
            "
          >
            <FiNavigation
              className="
                max-sm:size-4
                size-5
              "
            />
            <p
              className="
                overflow-hidden
                max-w-0 max-sm:text-xs
                font-bold whitespace-nowrap
                opacity-0 transition-all
                -translate-x-8 group-hover:max-w-xs group-hover:opacity-100 group-hover:ml-2 group-hover:translate-x-0 duration-300
              "
            >
              Reach out!
            </p>
          </Link>
          <Switch
            condition={darkTheme}
            setCondition={setDarkTheme}
            stickerActive={
              <MdOutlineDarkMode
                className="
                  text-blue-600
                  size-5
                "
              />
            }
            stickerInactive={
              <CiLight
                className="
                  text-blue-600
                  size-4
                "
              />
            }
            inactivebg="bg-blue-400"
            activebg="bg-slate-800"
            knob={`bg-white ${darkTheme ? "text-slate-900" : "text-amber-500"}`}
          />
        </div>
      </nav>
      <div ref={sideBarRef} className={`sidebar flex sm:hidden max-sm:flex-col max-sm:fixed max-sm:right-16 max-sm:top-20 max-sm:w-32 max-sm:h-60 max-sm:border max-sm:border-white/60 max-sm:p-8 max-sm:items-center max-sm:justify-between max-sm:backdrop-blur-xl max-sm:rounded-3xl max-sm:z-50 max-sm:bg-transparent dark:bg-zinc-800/20 dark:border-zinc-800/60 dark:shadow-2xl dark:text-slate-100 ${toggleSidebar ? "scale-100" : "scale-0 -translate-y-32 translate-x-20"} transition duration-300`}>
        <Link
          to="/"
          className="
              flex
              max-sm:gap-1
              rounded-sm
              cursor-pointer
              hover:px-4 hover:py-2 home group gap-2 items-center active::bg-blue-50 dark:hover:bg-zinc-800 hover:text-blue-600 dark:hover:text-slate-400
              active:scale-110 transition
            "
        >
          <FiHome
            className="
                max-sm:size-4
                size-5 shrink-0
              "
          />
          <p
            className="
                overflow-hidden
                max-w-0 max-sm:text-xs
                font-bold whitespace-nowrap
                opacity-0 transition-all
                -translate-x-8 group-hover:max-w-xs group-hover:opacity-100 group-hover:ml-2 group-hover:translate-x-0 duration-300
              "
          >
            Home
          </p>
        </Link>
        <Link
          to="/about"
          className="
              flex
              max-sm:gap-1
              rounded-sm
              cursor-pointer
              hover:px-4 hover:py-2 about group gap-2 items-center hover:bg-blue-50 dark:hover:bg-zinc-800 hover:text-blue-600 dark:hover:text-slate-400 active:scale-110 transition
            "
        >
          <FiInfo
            className="
                max-sm:size-4
                size-5 shrink-0
              "
          />
          <p
            className="
                overflow-hidden
                max-w-0 max-sm:text-xs
                font-bold whitespace-nowrap
                opacity-0 transition-all
                -translate-x-8 group-hover:max-w-xs group-hover:opacity-100 group-hover:ml-2 group-hover:translate-x-0 duration-300
              "
          >
            About
          </p>
        </Link>
        <Link
          to="/contact"
          className="
              flex
              max-sm:gap-1
              rounded-sm
              cursor-pointer
              hover:px-4 hover:py-2 contact group gap-2 items-center hover:bg-blue-50 dark:hover:bg-zinc-800 hover:text-blue-600 dark:hover:text-slate-400 active:scale-110 transition
            "
        >
          <FiNavigation
            className="
                max-sm:size-4
                size-5
              "
          />
          <p
            className="
                overflow-hidden
                max-w-0 max-sm:text-xs
                font-bold whitespace-nowrap
                opacity-0 transition-all
                -translate-x-8 group-hover:max-w-xs group-hover:opacity-100 group-hover:ml-2 group-hover:translate-x-0 duration-300
              "
          >
            Reach out!
          </p>
        </Link>
        <Switch
          condition={darkTheme}
          setCondition={setDarkTheme}
          stickerActive={
            <MdOutlineDarkMode
              className="
                  text-blue-600
                  size-5
                "
            />
          }
          stickerInactive={
            <CiLight
              className="
                  text-blue-600
                  size-4
                "
            />
          }
          inactivebg="bg-blue-400"
          activebg="bg-slate-800"
          knob={`bg-white ${darkTheme ? "text-slate-900" : "text-amber-500"}`}
        />
      </div>
      <main
        className="
          min-h-screen
          py-12 px-4
          bg-linear-to-br from-slate-50 via-blue-50/40 to-slate-100 bg-gray-300
          transition-colors
          dark:bg-linear-to-br dark:from-zinc-900 dark:via-zinc-950 dark:to-zinc-950 duration-300
          sm:px-6
        "
      >
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/about" element={<About />} />
          <Route path="/contact" element={<Contact />} />
        </Routes>
      </main>
    </BrowserRouter>
  );
}

export default App;
