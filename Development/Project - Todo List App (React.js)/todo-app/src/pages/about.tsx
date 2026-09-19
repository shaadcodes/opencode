import React from "react";
import {
  FiCheckCircle,
  FiDatabase,
  FiLayout,
  // FiServer,
  // FiShield,
  FiZap,
} from "react-icons/fi";

import {
  SiTailwindcss,
  SiTypescript,
  SiNodedotjs,
  SiExpress,
  SiMongodb,
  SiReact,
} from "react-icons/si";

const About: React.FC<{}> = () => {
  const techStack = [
    {
      name: "React 19",
      role: "Frontend UI",
      icon: SiReact,
      color: "text-cyan-500",
      bg: "bg-cyan-500/10",
    },
    {
      name: "TypeScript",
      role: "Type Safety",
      icon: SiTypescript,
      color: "text-blue-500",
      bg: "bg-blue-500/10",
    },
    {
      name: "Tailwind CSS",
      role: "Styling System",
      icon: SiTailwindcss,
      color: "text-sky-400",
      bg: "bg-blue-400/10",
    },
    {
      name: "Node.js",
      role: "Runtime Environment",
      icon: SiNodedotjs,
      color: "text-emerald-500",
      bg: "bg-emerald-500/10",
    },
    {
      name: "Express.js",
      role: "REST API Server",
      icon: SiExpress,
      color: "text-slate-700 dark:text-zinc-300",
      bg: "bg-slate-500/10",
    },
    {
      name: "MongoDB Atlas",
      role: "Cloud Database",
      icon: SiMongodb,
      color: "text-emerald-600",
      bg: "bg-emerald-600/10",
    },
  ];

  const coreFeatures = [
    {
      title: "Full CRUD Pipeline",
      desc: "Create, read, edit and delete tasks synced in real time.",
      icon: FiZap,
    },
    {
      title: "Cloud Persistent",
      desc: "Connected via Mongoose to MongoDB Atlas for uninterrupted sync across sessions.",
      icon: FiDatabase,
    },
    {
      title: "Smart Filtering",
      desc: "Filter active vs. completed tasks with dynamic progress indicators.",
      icon: FiCheckCircle,
    },
    {
      title: "Responsive & Themed",
      desc: "Optimized for mobile and desktop screens with seamless Light and Dark modes.",
      icon: FiLayout,
    },
  ];

  return (
    <main className="max-w-4xl mx-auto px-4 py-10 sm:py-14">
      <div className="architecture text-center max-w-2xl mx-auto mb-12">
        <span className="text-xs font-bold uppercase tracking-widest text-blue-600 dark:text-blue-400 bg-blue-50 dark:bg-blue-950/60 px-3 py-1.5 rounded-full border border-blue-200 dark:border-blue-800">
          Architecture & Overview
        </span>
        <h1 className="text-3xl sm:text-4xl font-extrabold text-slate-900 dark:text-zinc-100 mt-4 tracking-tight">
          About
        </h1>
        <p className="description text-slate-600 dark:text-zinc-400 mt-3 text-base sm:text-lg leading-relaxed">
          A modern full-stack task manager built to demonstrate robust state
          management, RESTful API architecture, and dynamic theming with the
          MERN stack.
        </p>
      </div>
      <section className="mb-12">
        <h2 className="technologies text-sm font-semibold uppercase tracking-wider text-slate-500 dark:text-zinc-400 mb-4 text-center sm:text-left">
          Technologies Used
        </h2>
        <div className="techGrid grid grid-col-2 sm:grid-cols-3 gap-4">
          {techStack.map((tech) => (
            <div
              key={tech.name}
              className="flex items-center gap-3.5 p-4 rounded-2xl bg-white/70 dark:bg-zinc-900/80 border border-slate-200/80 dark:border-zinc-800 shadow-md hover:border-blue-400/50 dark:hover:border-blue-500/30 transition duration-300"
            >
              <div
                className={`p-2.5 rounded-xl ${tech.bg} ${tech.color} flex items-center justify-center shrink-0`}
              >
                <tech.icon className="icon size-6" />
              </div>
              <div className="truncate">
                <h3 className="text-sm font-semibold text-slate-800 dark:text-zinc-100 truncate">
                  {tech.name}
                </h3>
                <p className="text-xs text-slate-500 dark:text-zinc-400 truncate">
                  {tech.role}
                </p>
              </div>
            </div>
          ))}
        </div>
      </section>
      <section>
        <h2 className="text-sm font-semibold uppercase tracking-wider text-slate-500 dark:text-zinc-400 mb-4 text-center sm:text-left">
          Core Capabilities
        </h2>
        <div className="grid grid-cols-1 sm:grid-cols-2 gap-4">
          {coreFeatures.map((feature) => (
            <div
              key={feature.title}
              className="p-6 rounded-3xl bg-white/70 dark:bg-zinc-900/80 border border-slate-200/80 dark:border-zinc-800 shadow-sm flex flex-col justify-between"
            >
              <div className="flex items-center gap-3 mb-3">
                <div className="p-2 rounded-lg bg-blue-50 dark:bg-blue-950/60 text-blue-600 dark:text-blue-400">
                  <feature.icon className="size-5" />
                </div>
                <h3 className="text-base font-bold text-slate-800 dark:text-zinc-100">
                  {feature.title}
                </h3>
              </div>
              <p className="text-sm text-slate-600 dark:text-zinc-400 leading-relaxed">
                {feature.desc}
              </p>
            </div>
          ))}
        </div>
      </section>
    </main>
  );
};

export default About;
