library(MASS)

data <- MASS::Boston

dataprime <- data[1:5]

png("scatter.png", bg = "transparent")
pairs(dataprime)
title(main = "scatter plots")
dev.off()