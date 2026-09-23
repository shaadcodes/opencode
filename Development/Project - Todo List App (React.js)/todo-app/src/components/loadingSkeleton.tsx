import React from 'react'

const LoadingSkeleton: React.FC<{}> = () => {
  return (
    <div className='space-y-3 py-2 flex flex-col grow'>
        {[1, 2, 3].map((item) => (
            <div
            key={item}
            className='flex items-center justify-between p-3.5 bg-slate-100/80 dark:bg-zinc-800/40 border border-slate-200/60 dark:border-zinc-800/80 rounded-2xl animate-pulse w-full'
            >
                <div className='flex items-center gap-3 w-full'>
                    <div className='size-4 rounded bg-slate-300 dark:bg-zinc-700 shrink-0'/>
                    <div 
                    className={`h-4 rounded-md bg-slate-300 dark:bg-zinc-700 ${item === 1 ? "w-3/5" : item === 2 ? "w-4/5" : "w-1/2"}`}
                    ></div>
                </div>
                <div className='flex items-center gap-2 shrink-0'>
                    <div className="size-7 rounded-lg bg-slate-200 dark:bg-zinc-700/60" />
                    <div className="size-7 rounded-lg bg-slate-200 dark:bg-zinc-700/60" />
                </div>
            </div>
        ))}
    </div>
  )
}

export default LoadingSkeleton;