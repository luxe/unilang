import { getGuessStatuses } from '../../lib/statuses'
import { Cell } from './Cell'
import { unicodeSplit } from '../../lib/words'
import { MAX_WORD_LENGTH, MIDDLE_WORD_LENGTH } from '../../constants/settings'

type Props = {
  guess: string
  isRevealing?: boolean
}

export const CompletedRow = ({ guess, isRevealing }: Props) => {
  const statuses = getGuessStatuses(guess)
  const splitGuess = unicodeSplit(guess)

  return (
    <div className="flex justify-center mb-1">
    
      {splitGuess.length == MIDDLE_WORD_LENGTH && (
        <Cell key={0} value={"🥬"} />
      )}
      
      {splitGuess.map((letter, i) => (
        <Cell
          key={i}
          value={letter}
          status={statuses[i]}
          position={i}
          isRevealing={isRevealing}
          isCompleted
        />
      ))}
      
      {splitGuess.length == MIDDLE_WORD_LENGTH && (
        <Cell key={4} value={"🥬"} />
      )}
      
    </div>
  )
}
