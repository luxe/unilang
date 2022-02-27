export const GAME_TITLE = process.env.REACT_APP_GAME_NAME!

export const WIN_MESSAGES = ['美味！', '好吃！', '我飽了！']
export const GAME_COPIED_MESSAGE = 'Meal copied to clipboard'
export const EMPTY_LETTERS_MESSAGE = 'Your plate is empty!'
export const NOT_ENOUGH_LETTERS_MESSAGE = 'Take a bigger bite!'
export const WORD_NOT_FOUND_MESSAGE = "That's not edible!"
export const HARD_MODE_ALERT_MESSAGE =
  'Hard Mode can only be enabled at the start!'
export const CORRECT_WORD_MESSAGE = (solution: string) =>
  `The word was ${solution}`
export const WRONG_SPOT_MESSAGE = (guess: string, position: number) =>
  `Must use ${guess} in position ${position}`
export const NOT_CONTAINED_MESSAGE = (letter: string) =>
  `Guess must contain ${letter}`
export const ENTER_TEXT = 'Enter'
export const DELETE_TEXT = 'Delete'
export const STATISTICS_TITLE = 'Meals'
export const GUESS_DISTRIBUTION_TEXT = 'Bites'
export const NEW_WORD_TEXT = 'New meal in'
export const SHARE_TEXT = 'Share'
export const TOTAL_TRIES_TEXT = 'Total meals'
export const SUCCESS_RATE_TEXT = 'Happiness'
export const CURRENT_STREAK_TEXT = 'Current streak'
export const BEST_STREAK_TEXT = 'Best streak'


