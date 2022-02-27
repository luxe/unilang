import { getGuessStatuses } from './statuses'
import { solutionIndex } from './words'
import { GAME_TITLE } from '../constants/strings'
import { MAX_CHALLENGES, MIDDLE_WORD_LENGTH } from '../constants/settings'

export const shareStatus = (
  guesses: string[],
  lost: boolean,
  isHardMode: boolean,
  isDarkMode: boolean,
  isHighContrastMode: boolean
) => {
  navigator.clipboard.writeText(
    `${GAME_TITLE} ${solutionIndex} ${
      lost ? 'X' : guesses.length
    }/${MAX_CHALLENGES}${isHardMode ? '*' : ''}\n\n` +
      generateEmojiGrid(guesses, getEmojiTiles(isDarkMode, isHighContrastMode))
  )
}

export const generateEmojiGrid = (guesses: string[], tiles: string[]) => {
  return guesses
    .map((guess) => {
      const status = getGuessStatuses(guess)
      var row = guess
        .split('')
        .map((_, i) => {
          switch (status[i]) {
            case 'correct':
              return tiles[0]
            case 'present':
              return tiles[1]
            default:
              return tiles[2]
          }
        })
        .join('');
        
        if (guess.length == MIDDLE_WORD_LENGTH){
          row = '🥬' + row;
          row += '🥬';
        }
        
        return row
        
        // if (guess.length == MIDDLE_WORD_LENGTH){
        //   tiles
        // }
    })
    .join('\n')
}

const getEmojiTiles = (isDarkMode: boolean, isHighContrastMode: boolean) => {
  let tiles: string[] = []
  tiles.push(isHighContrastMode ? '🟢' : '🟢')
  tiles.push(isHighContrastMode ? '🌕' : '🌕')
  tiles.push(isDarkMode ? '🍚' : '🍚')
  return tiles
}