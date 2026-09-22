import { FiInbox, FiPlus } from 'react-icons/fi';

const EmptyState = ({ onFocusInput }: { onFocusInput?: () => void }) => {
  return (
    <div className='flex flex-col items-center justify-center py-16 px-4 text-center'>
        <div className='relative mb-5 flex items-center justify-center'>
            <div className='absolute size-16 rounded-3xl bg-blue-500/10 dark:to-blue-400/10 blur-xl'/>
            <div className="relative size-14 rounded-2xl bg-slate-100 dark:bg-zinc-800/80 border border-zinc-700/6 flex items-center justify-center text-blue-400 shadow-sm">
            <FiInbox className="size-7 stroke-[1.75]"/>
            </div>
        </div>
        <h3 className="text-base font-bold text-slate-800 dark:text-zinc-100">All Caught Up!</h3>
        <p className="text-xs sm:text-sm text-slate-500 dark:text-zinc-400 max-w-xs mt-1.5 leading-relaxed">You don't have any tasks pending right now. Add a task to plan your day.</p>
        {onFocusInput && (
            <button
            onClick={onFocusInput}
            className='mt-10 inline-flex max-sm:flex-col items-center gap-2 max-sm:gap-2 px-6 max-sm:px-4 py-4 max-sm:py-2 rounded-xl bg-slate-100 dark:bg-zinc-800 hover:bg-slate-200 dark:hover:bg-zinc-700 text-xs font-semibold text-slate-700 dark:text-zinc-300 transition active:scale-95'
            >
                <FiPlus className="size-3.5 max-sm:hidden" />
                <span>New Task</span>
            </button>
        )}
    </div>
  )
}

export default EmptyState