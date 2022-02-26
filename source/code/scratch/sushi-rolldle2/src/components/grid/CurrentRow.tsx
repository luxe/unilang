import { MAX_WORD_LENGTH, MIDDLE_WORD_LENGTH } from '../../constants/settings'
import { Cell } from './Cell'
import { unicodeSplit } from '../../lib/words'

type Props = {
  guess: string
  className: string
  guessingInner: boolean
}

export const CurrentRow = ({ guess, className, guessingInner}: Props) => {
  const splitGuess = unicodeSplit(guess)
  const emptyCells = Array.from(Array(guessingInner ? MIDDLE_WORD_LENGTH - splitGuess.length: MAX_WORD_LENGTH - splitGuess.length))
  const classes = `flex justify-center mb-1 ${className}`

  return (
          
      
      
    <div className={classes}>
    
      {guessingInner && (
        <Cell key={0} value={"🥬"} />
      )}
      
      {splitGuess.map((letter, i) => (
        <Cell key={i} value={letter} />
      ))}
      {emptyCells.map((_, i) => (
        <Cell key={i} value={"🍚"} />
      ))}
      
      {guessingInner && (
        <Cell key={4} value={"🥬"} />
      )}
      
    </div>
  )
}
