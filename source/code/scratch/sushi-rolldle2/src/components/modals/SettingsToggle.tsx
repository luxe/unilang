import classnames from 'classnames'

type Props = {
  settingName: string
  flag: boolean
  handleFlag: Function
}

export const SettingsToggle = ({ settingName, flag, handleFlag }: Props) => {
  const toggleHolder = classnames(
    'w-14 h-8 flex items-center bg-gray-300 rounded-full p-1 duration-300 ease-in-out cursor-pointer',
    {
      'bg-green-400': flag,
    }
  )
  const toggleButton = classnames(
    'bg-white w-6 h-6 rounded-full shadow-md transform duration-300 ease-in-out cursor-pointer',
    {
      'translate-x-6': flag,
    }
  )
  return (
    <div className="flex justify-between items-center gap-8 mt-2">
      <h2 className="text-gray-500 dark:text-gray-300">{settingName}</h2>
      <div className={toggleHolder} onClick={() => handleFlag(!flag)}>
        <div className={toggleButton} />
      </div>
    </div>
  )
}
