import { Cell } from '../grid/Cell'
import { BaseModal } from './BaseModal'

type Props = {
  isOpen: boolean
  handleClose: () => void
}

export const InfoModal = ({ isOpen, handleClose }: Props) => {
  return (
    <BaseModal title="How to Eat" isOpen={isOpen} handleClose={handleClose}>
      <p className="text-sm text-gray-500 dark:text-gray-300">
        Guess the middle word then the full word.
      </p>
      
      <div className="flex justify-center mb-1 mt-4">
        <Cell value="🥬" />
<Cell value="O" />
<Cell value="N" />
<Cell value="E" />
        <Cell value="🥬" />
      </div>
      <div className="flex justify-center mb-1 mt-4">
<Cell value="H" />
<Cell value="O" />
<Cell value="N" />
<Cell value="E" />
<Cell value="Y" />
      </div>
      

      <p className="mt-6 italic text-sm text-gray-500 dark:text-gray-300">
              <p className="text-sm text-gray-500 dark:text-gray-300">
        Dipping Sauces:
      </p>
      </p>

      <div className="flex justify-center mb-1 mt-4">
        <Cell
          isRevealing={true}
          isCompleted={true}
          value="S"
          status="correct"
        />
        <Cell value="U" />
        <Cell value="S" />
        <Cell value="H" />
        <Cell value="I" />
      </div>
      <p className="text-sm text-gray-500 dark:text-gray-300">
        Wasabi! The letter S is in the correct spot.
      </p>

      <div className="flex justify-center mb-1 mt-4">
        <Cell value="Y" />
        <Cell
          isRevealing={true}
          isCompleted={true}
          value="U"
          status="present"
        />
        <Cell value="M" />
        <Cell value="M" />
        <Cell value="Y" />
      </div>
      <p className="text-sm text-gray-500 dark:text-gray-300">
        Ginger! The letter U is in the wrong spot.
      </p>

      <div className="flex justify-center mb-1 mt-4">
        <Cell value="C" />
        <Cell value="H" />
        <Cell value="I" />
        <Cell isRevealing={true} isCompleted={true} value="N" status="absent" />
        <Cell value="A" />
      </div>
      <p className="text-sm text-gray-500 dark:text-gray-300">
        Soy! The letter N is not in the word.
      </p>

      <p className="mt-6 italic text-sm text-gray-500 dark:text-gray-300">
              <p className="text-sm text-gray-500 dark:text-gray-300">
        Color hints apply to the entire word.  Hope your hungry!
      </p>
      </p>
    </BaseModal>
  )
}
