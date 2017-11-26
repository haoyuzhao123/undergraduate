library(MASS)

data <- MASS::Boston

png(file = "1.png",bg = "white")
boxplot(data[[1]])
title(main = "crim")
dev.off()

png(file = "2.png",bg = "white")
boxplot(data[[2]])
title(main = "zn")
dev.off()

png(file = "3.png",bg = "transparent")
boxplot(data[[3]])
title(main = "indus")
dev.off()

png(file = "4.png",bg = "transparent")
boxplot(data[[4]])
title(main = "chas")
dev.off()

png(file = "5.png",bg = "transparent")
boxplot(data[[5]])
title(main = "nox")
dev.off()

png(file = "6.png",bg = "transparent")
boxplot(data[[6]])
title(main = "rm")
dev.off()

png(file = "7.png",bg = "transparent")
boxplot(data[[7]])
title(main = "age")
dev.off()

png(file = "8.png",bg = "transparent")
boxplot(data[[8]])
title(main = "dis")
dev.off()

png(file = "9.png",bg = "transparent")
boxplot(data[[9]])
title(main = "rad")
dev.off()

png(file = "10.png",bg = "transparent")
boxplot(data[[10]])
title(main = "tax")
dev.off()

png(file = "11.png",bg = "transparent")
boxplot(data[[11]])
title(main = "ptratio")
dev.off()

png(file = "12.png",bg = "transparent")
boxplot(data[[12]])
title(main = "black")
dev.off()

png(file = "13.png",bg = "transparent")
boxplot(data[[13]])
title(main = "lstat")
dev.off()

png(file = "14.png",bg = "transparent")
boxplot(data[[14]])
title(main = "medv")
dev.off()