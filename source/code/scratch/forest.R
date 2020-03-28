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
    panel.border = element_rect(color = "grey", fill = NA, size = .5)
  )
}

limit_line_height=.5
limit_line_thickness=1
point_estimate_thickness=.5
title="Odds ratios of birth outcomes among excessive weight gain stratified by race: normal weight gain as reference group"
x_label="Outcomes"
y_label="Odds Ratio at 95% CI"

Parameter  = c("Preterm birth", "SGA", "LGA", "LBW", "Macrosomia", "Low Apgar")
Subparameter = c("White","White","White","White","White","White","Black","Black","Black","Black","Black","Black")
OR    = c(0.74, 0.63, 1.89, 0.61, 2.01, 0.82, 0.75, 0.71, 1.78, 0.66, 1.95, 0.76)
Lower = c(0.73, 0.63, 1.87, 0.60, 1.99, 0.79, 0.73, 0.69, 1.74, 0.64, 1.89, 0.71)
Upper = c(0.75, 0.64, 1.91, 0.62, 2.03, 0.85, 0.77, 0.72, 1.84, 0.67, 2.02, 0.81)

dat = data.frame(Parameter, OR, Lower, Upper)



dat$Parameter = factor(dat$Parameter, levels=c("Preterm birth", "SGA", "LGA", "LBW", "Macrosomia", "Low Apgar")) 
g = ggplot(data=dat, aes(x=Subparameter, y=OR, ymin=Lower, ymax=Upper, color=Parameter))
g = g + geom_pointrange(aes(col=Subparameter), lwd=point_estimate_thickness)  
g = g + geom_hline(aes(fill=Subparameter), yintercept =1, linetype=2)
g = g + ggtitle(title)
g = g + xlab(x_label) + ylab(y_label)
g = g + geom_errorbar(aes(ymin=Lower, ymax=Upper, col=Subparameter), width=limit_line_height, cex=limit_line_thickness)
g = g + facet_wrap(~Parameter, strip.position="left", nrow=9, scales = "free_y")
# g = g + theme(plot.title=element_text(size=16,face="bold"),
#         axis.text.y=element_blank(),
#         axis.ticks.y=element_blank(),
#         axis.text.x=element_text(face="bold"),
#         axis.title=element_text(size=10,face="bold"),
#         strip.text.y = element_text(hjust=0,vjust = 1,angle=180,face="bold"))
g = g + coord_flip() + theme_bw() + theme(legend.position="none", axis.title = element_text(size = 8))


png("myplot.png")

ggsave(file="myplot2.png", width=11, height=6, dpi=100)
print(g)
dev.off()





#odds ratio
# relative risk ratio


# ** var, black/white, odds ratio, confidence interval
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