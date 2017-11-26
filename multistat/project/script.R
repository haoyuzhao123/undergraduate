########################################################################
#----------------------begin of the project code------------------------
library(ggplot2)
library(corrplot)

#----------------------read the data from the data set------------------
raw_data <- read.csv('PRSA_data_2010.1.1-2014.12.31.csv', header = TRUE)
data_basic <- subset(raw_data, is.na(pm2.5)==FALSE)

#----------------------some descriptice statistics----------------------
ggplot(data_basic) + geom_histogram(aes(x=pm2.5), binwidth = 15)
ggplot(data_basic) + geom_line(aes(x = No, y = pm2.5))
summary(data_basic$pm2.5)

data_basic.night <- subset(data_basic, hour < 8 | hour >= 20)
data_basic.day <- subset(data_basic, hour >= 8 & hour < 20)
ggplot(data_basic.day) + geom_histogram(aes(x=pm2.5), binwidth = 15)
ggplot(data_basic.night) + geom_histogram(aes(x=pm2.5), binwidth = 15)

mean(data_basic.day$pm2.5)
mean(data_basic.night$pm2.5)

var(data_basic.day$pm2.5)
var(data_basic.night$pm2.5)

#the mean of each year
t <- rep(0,5)

for (i in 2010:2014) {
  temp <- subset(data_basic, year==i)
  t[i-2009] = mean(temp$pm2.5)
}

plot(t, xlab = 'year', ylab = 'pm2.5')

#the mean of the pm2.5 of each hour
mean_pm <- rep(0,24)
for(i in 0:23) {
  mean_pm[i+1] = mean(subset(data_basic, hour == i)$pm2.5)
}
plot(mean_pm)
ggplot(data_basic, aes(x=factor(hour), y=pm2.5)) + geom_boxplot()

#the mean of the pm2.5 of each month
mean_pm <- rep(0,12)
for(i in 1:12) {
  mean_pm[i] = mean(subset(data_basic, month == i)$pm2.5)
}
plot(mean_pm)
ggplot(data_basic, aes(x=factor(month), y=pm2.5)) + geom_boxplot()

#the relation of different variables
reg_var <- data_basic[,c(6,7,8,9,11,12,13)]
corrplot(cor(reg_var), method='square')


qplot(Iws, pm2.5, data=reg_var)
qplot(DEWP, pm2.5, data=reg_var)
qplot(TEMP, pm2.5, data=reg_var)
qplot(Iws, pm2.5, data=subset(data_basic, cbwd=='NW'))

cormat <- cor(reg_var)
R12 <- cormat[1,2:7]
R21 <- cormat[2:7,1]
R22 <- cormat[2:7,2:7]

R2 <- solve(R22) %*% R21 %*% R12
t <- eigen(R2)
cor(reg_var[,1], as.matrix(reg_var[,-1]) %*% as.matrix(t$vectors[,1]))

data_new <- data_basic[,6:13]
data.cv <- subset(data_new, cbwd == 'cv')[,-5]
data.NE <- subset(data_new, cbwd == 'NE')[,-5]
data.NW <- subset(data_new, cbwd == 'NW')[,-5]
data.SE <- subset(data_new, cbwd == 'SE')[,-5]

centers <- matrix(0,4,7)

centers[1,] = apply(data.cv, 2, mean)
centers[2,] = apply(data.NE, 2, mean)
centers[3,] = apply(data.NW, 2, mean)
centers[4,] = apply(data.SE, 2, mean)

S <- cov(reg_var)

mahal <- matrix(0,4,4)
for (i in 1:4) {
  mahal[i,] = mahalanobis(centers, centers[i,], S)
}

coords <- cmdscale(mahal)
plot(coords, type = 'n')
text(coords, labels = c('cv','NE','NW','SE'),
     col = c(1,2,3,4))
