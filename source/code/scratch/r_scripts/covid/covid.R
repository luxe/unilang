require (astsa)
dat <- read.csv("https://raw.githubusercontent.com/nytimes/covid-19-data/master/us.csv")
dead <- c()
case <- c()
k <- length(dat$deaths)
while (k >= 1) {
  if (k == 1) {
    dead[k] <- 0
  } else {
    dead[k] <- dat$deaths[k] - dat$deaths[k-1]
    case[k] <- dat$cases[k] - dat$cases[k-1]
  }
  k <- k - 1
}
case[1] <- 1
lag2.plot(case, dead, 20, col="dodgerblue3")
