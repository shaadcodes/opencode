import React, { type ReactNode } from 'react'
interface SwitchProps {
    condition: boolean,
    setCondition: (condition: any) => void,
    stickerActive?: ReactNode,
    stickerInactive?: ReactNode,
    inactivebg?: string,
    activebg?: string,
    knob?: string,
}

const Switch: React.FC<SwitchProps> = ({condition, setCondition, stickerActive, stickerInactive, activebg="bg-blue-600", inactivebg="bg-gray-400", knob="bg-white"}) => {
  return (
    <button
            type="button"
            role="switch"
            aria-checked={condition}
            onClick={() => setCondition((condition: boolean) => !condition)}
            className={`relative inline-flex h-6 w-11 shrink-0 cursor-pointer rounded-full border-2 border-transparent transition-colors duration-300 ease-in-out focus:outline-none ${condition ?  activebg : inactivebg }`}
          >
            <span
              className={`pointer-events-none inline-flex items-center justify-center size-5 transform rounded-full ${knob} shadow-md ring-0 transition duration-100 ease-in-out ${condition ? "translate-x-5" : "translate-x-0"}`}
            >{condition ? stickerActive : stickerInactive}</span>
    </button>
  )
}

export default Switch;
