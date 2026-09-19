import React, { useState } from "react";
import {
  // FiMail,
  FiSend,
  FiCopy,
  FiCheck,
  FiGithub,
  FiLinkedin,
  FiMessageSquare,
} from "react-icons/fi";

const Contact: React.FC<{}> = () => {
  const [copied, setCopied] = useState(false);
  const [formData, setFormData] = useState({
    name: "",
    email: "",
    message: "",
  });
  const [status, setStatus] = useState<"idle" | "sending" | "sent">("idle");
  const email = "shaadsgfx@gmail.com";

  const handleCopyEmail = () => {
    navigator.clipboard.writeText(email);
    setCopied(true);
    setTimeout(() => {
      setCopied(false);
    }, 3000);
  };

  const handleSubmit = (e: React.FormEvent) => {
    e.preventDefault();
    if (!formData.name || !formData.email || !formData.message) return;
    setStatus("sending");
    setTimeout(() => {
      setStatus("sent");
      setFormData({
        name: "",
        email: "",
        message: "",
      });
      setTimeout(() => setStatus("idle"), 3000);
    }, 1000);
  };

  return (
    <main className="max-w-4xl mx-auto px-4 py-10 sm:py-14">
      <div className="text-center max-w-xl mx-auto mb-10">
        <span className="text-xs font-bold uppercase tracking-widest text-blue-600 dark:text-blue-400 bg-blue-50 dark:bg-blue-950/60 px-3 py-1.5 rounded-full border border-blue-200 dark:border-blue-800">
          Connect
        </span>
        <h1 className="text-3xl sm:text-4xl font-extrabold text-slate-900 dark:text-zinc-100 mt-4 tracking-tight">
          Get in Touch
        </h1>
        <p className="text-slate-600 dark:text-zinc-400 mt-3 text-sm sm:text-base">
          Have questions, suggestions, or want to collaborate on a project? Send
          me a message!
        </p>
      </div>
      <div className="grid grid-cols-1 md:grid-cols-5 gap-6 items-start">
        <div className="md:col-span-2 space-y-4">
          <div className="p-6 rounded-3xl bg-white/70 dark:bg-zinc-900/80 border border-slate-200/80 dark:border-zinc-800 shadow-sm space-y-5">
            <h2 className="text-base font-bold text-slate-800 dark:text-zinc-100 flex items-center gap-2">
              <FiMessageSquare className="text-blue-600 dark:text-blue-400" />
              Direct Channels
            </h2>
            <div className="p-3.5 rounded-2xl bg-slate-50 dark:bg-zinc-800/50 border border-slate-200/60 dark:border-zinc-800 flex items-center justify-between">
              <div className="truncate mr-2">
                <p className="text-xs text-slate-400 font-medium">
                  Email Address
                </p>
                <p className="text-sm font-semibold text-slate-800 dark:text-zinc-200 truncate">
                  {email}
                </p>
              </div>
              <button
                onClick={handleCopyEmail}
                className="p-2 rounded-xl bg-white dark:bg-zinc-700 text-slate-600 dark:text-zinc-200 hover:text-blue-600 dark:hover:text-blue-400 shadow-sm transition shrink-0"
              >
                {copied ? (
                  <FiCheck className="size-4 text-emerald-500" />
                ) : (
                  <FiCopy className="size-4" />
                )}
              </button>
            </div>
            <div className="social space-y-2.5 pt-2">
              <a
                href="https://www.github.com/shaadcodes/opencode"
                target="_blank"
                rel="noopener noreferrer"
                className="flex items-center justify-between p-3 rounded-2xl bg-slate-50 dark:bg-zinc-800/40 border border-slate-200/60 dark:border-zinc-800 text-slate-700 dark:text-zinc-300 hover:border-blue-600 dark:hover:text-blue-400 transition"
              >
                <div className="flex items-center gap-3">
                  <FiGithub className="size-5" />
                  <span className="text-sm font-semibold">
                    GitHub Repository
                  </span>
                </div>
                <span className="text-xs text-slate-400"></span>
              </a>
              <a
                href="https://www.linkedin.com/in/shaadcodes"
                target="_blank"
                rel="noopener noreferrer"
                className="flex items-center justify-between p-3 rounded-2xl bg-slate-50 dark:bg-zinc-800/40 border border-slate-200/60 dark:border-zinc-800 text-slate-700 dark:text-zinc-300 hover:border-blue-600 dark:hover:text-blue-400 transition"
              >
                <div className="flex items-center gap-3">
                  <FiLinkedin className="size-5 text-[#0a66c2]" />
                  <span className="text-sm font-semibold">
                    LinkedIn Profile
                  </span>
                </div>
                <span className="text-xs text-slate-400"></span>
              </a>
            </div>
          </div>
        </div>
        <div className="md:col-span-3 p-6 sm:p-8 rounded-3xl bg-white/70 dark:bg-zinc-900/80 border border-slate-200/80 dark:border-zinc-800 shadow-sm">
          <form onSubmit={handleSubmit} className="space-y-4">
            <div>
              <label className="block text-xs font-semibold uppercase tracking-wider text-slate-500 dark:text-zinc-400 mb-1.5">
                Your Name
              </label>
              <input
                type="text"
                required
                value={formData.name}
                onChange={(e) =>
                  setFormData({ ...formData, name: e.target.value })
                }
                placeholder="Enter name..."
                className="w-full px-4 rounded-xl bg-slate-50 dark:bg-zinc-800/50 border border-slate-200/80 dark:border-zinc-700/80 text-slate-800 dark:text-zinc-100 placeholder-slate-400 focus:outline-none focus:ring-2 focus:ring-blue-500/20 focus:border-blue-500 text-sm transition p-2 mt-2"
              />
            </div>
            <div>
              <label className="block text-xs font-semibold uppercase tracking-wider text-slate-500 dark:text-zinc-400 mb-1.5">
                Your Email Address
              </label>
              <input
                type="email"
                required
                value={formData.email}
                onChange={(e) =>
                  setFormData({ ...formData, email: e.target.value })
                }
                placeholder="name@example.com"
                className="w-full px-4 rounded-xl bg-slate-50 dark:bg-zinc-800/50 border border-slate-200/80 dark:border-zinc-700/80 text-slate-800 dark:text-zinc-100 placeholder-slate-400 focus:outline-none focus:ring-2 focus:ring-blue-500/20 focus:border-blue-500 text-sm transition p-2 mt-2"
              />
            </div>
            <div>
              <label className="block text-xs font-semibold uppercase tracking-wider text-slate-500 dark:text-zinc-400 mb-1.5">
                Message
              </label>
              <textarea
                rows={4}
                required
                value={formData.message}
                onChange={(e) =>
                  setFormData({ ...formData, message: e.target.value })
                }
                placeholder="Write to me..."
                className="w-full px-4 rounded-xl bg-slate-50 dark:bg-zinc-800/50 border border-slate-200/80 dark:border-zinc-700/80 text-slate-800 dark:text-zinc-100 placeholder-slate-400 focus:outline-none focus:ring-2 focus:ring-blue-500/20 focus:border-blue-500 text-sm transition resize-none p-4 mt-2"
              />
            </div>
            <button
              type="submit"
              disabled={status === "sending"}
              className="w-full py-3 px-4 rounded-xl bg-blue-600 hover:bg-blue-700 active:scale-[0.99] text-white text-sm font-semibold flex items-center justify-center gap-2 shadow-sm transition disabled:opacity-70"
            >
              {status === "sending" ? (
                <span>Sending...</span>
              ) : status === "sent" ? (
                <span className="flex items-center gap-2 text-emerald-100">
                  <FiCheck className="size-4" /> Message Received!
                </span>
              ) : (
                <FiSend className="size-4">Send Message</FiSend>
              )}
            </button>
          </form>
        </div>
      </div>
    </main>
  );
};

export default Contact;
