library(ggplot2)
## Registered S3 methods overwritten by 'ggplot2':
##   method         from 
##   [.quosures     rlang
##   c.quosures     rlang
##   print.quosures rlang
mytheme <- function(base_size = 12, base_family = "sans"){
  theme_minimal(base_size = base_size, base_family = base_family) +
  theme(
    axis.text = element_text(size = 12),
    axis.title = element_text(size = 14),
    panel.grid.major = element_line(color = "grey"),
    panel.grid.minor = element_blank(),
    panel.background = element_rect(fill = "aliceblue"),
    strip.background = element_rect(fill = "darkgrey", color = "grey", size = 1),
    strip.text = element_text(face = "bold", size = 12, color = "white"),
    legend.position = " ",
    legend.justification = "top", 
    panel.border = element_rect(color = "grey", fill = NA, size = 0.5)
  )
}

Parameter  = c("Hip fx", "Vertebral fx", "Major fx", "Minor fx", "Hip fx", "Vertebral fx", "Major fx", "Minor fx")
Sex = c(rep("Women", 4), rep("Men", 4))
RR = c(2.53, 1.76, 1.60, 1.38, 3.52, 2.26, 2.01, 1.64)
Lower = c(2.04, 1.43, 1.20, 1.10, 2.58, 1.72, 1.38, 1.16)
Upper = c(3.13, 2.17, 2.13, 1.74, 4.80, 2.98, 2.92, 2.31)

dat = data.frame(Parameter, RR, Lower, Upper)

dat$Parameter = factor(dat$Parameter, levels=c("Hip fx", "Vertebral fx", "Major fx", "Minor fx")) 
g = ggplot(data=dat, aes(x=Sex, y=RR, ymin=Lower, ymax=Upper, color=Parameter))
g = g + geom_pointrange(aes(col=Sex), lwd=0.8)  
g = g + geom_hline(aes(fill=Sex), yintercept =1, linetype=2)
g = g + xlab("") + ylab("Risk Ratio (95% Confidence Interval)")
g = g + geom_errorbar(aes(ymin=Lower, ymax=Upper, col=Sex), width=0.5, cex=1)
g = g + facet_wrap(~Parameter, strip.position="left", nrow=9, scales = "free_y")
g = g + theme(plot.title=element_text(size=16,face="bold"),
        axis.text.y=element_blank(),
        axis.ticks.y=element_blank(),
        axis.text.x=element_text(face="bold"),
        axis.title=element_text(size=12,face="bold"),
        strip.text.y = element_text(hjust=0,vjust = 1,angle=180,face="bold"))
g + coord_flip() + theme_bw() + theme(legend.position="none")




# 1 1 0.74 0.73 0.75
# 1 2 0.75 0.73 0.77
# 2 1  0.63 0.63 0.64
# 2 2 0.71 0.69 0.72
# 3 1 1.89 1.87 1.91
# 3 2 1.78 1.74 1.84
# 4 1 0.61 0.60 0.62
# 4 2 0.66 0.64 0.67
# 5 1 2.01 1.99 2.03
# 5 2 1.95 1.89 2.02
# 6 1 0.82 0.79 0.85
# 6 2 0.76 0.71 0.81