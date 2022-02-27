import { GameStats } from '../../lib/localStorage'
import { Progress } from './Progress'
import {
  MAX_CHALLENGES,
} from '../../constants/settings'

type Props = {
  gameStats: GameStats
}

export const Histogram = ({ gameStats }: Props) => {
  const winDistribution = gameStats.winDistribution
  const maxValue = Math.max(...winDistribution)
  //const maxValue = MAX_CHALLENGES + 3

  return (
    <div className="columns-1 justify-left m-2 text-sm dark:text-white">
      {winDistribution.map((value, i) => (
         i != 0 &&
        <Progress
          key={i}
          index={i}
          size={90 * (value / maxValue)}
          label={String(value)}
        />
      ))}
    </div>
  )
}
