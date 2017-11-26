library(MASS)
library(distances)
#loading the data from the data set
readdata <- read.csv('./Wholesale customers data.csv')

#a new data frame without the first 2 attribute, Channel and Region
data_new <- readdata[,3:8]
dim(data_new)
data_new <- as.matrix(data_new)
dim(data_new)

labs <- rep(0,440)
for (i in 1:440) {
  labs[i] <- (readdata$Channel[i]-1) * 3 + readdata$Region[i]
}

labs <- matrix(labs,440,1)

data_new <- cbind(labs, data_new)

centres <- matrix(0,6,6)
S <- as.matrix(var(data_new[,-1]))

mahal <- matrix(0,6,6)

for(i in 1:6) {
  centres[i,] <- apply(data_new[labs==i,-1],2,mean)
}

for(i in 1:440) {
  mahal[i,] = mahalanobis(centres, centres[i,], S)
}

coords <- cmdscale(mahal)
plot(coords, type = 'n')
text(coords, labels = c(1,2,3,1,2,3),
     col = c(1,1,1,2,2,2))









#calculating the distance
#using the mahalanobis distance
#data_new.mahal <- distances(data_new, normalize='mahalanobis')
#data_new.dist <- as.matrix(distance_matrix(data_new.mahal))
data_new.dist <- mahalanobis.dist(data_new)

#do the MDS
data_new.mds <- cmdscale(data_new.dist, k=339, eig=T)

#plot the result
par(pty='s')
plot(data_new.mds$points[,1], data_new.mds$points[,2],type='n')
text(data_new.mds$points[,1], data_new.mds$points[,2], 
     labels=readdata$Region,col=readdata$Channel)

#zoom part of the graph, in which the points are much more than other parts
temp <- c()
for (i in 1:440) {
  if (data_new.mds$points[,1][i] < 2 & data_new.mds$points[,1][i] > -2) {
    temp <- append(temp,i)
  }
}

#plot the result
par(pty='s')
plot(data_new.mds$points[,1][temp], data_new.mds$points[,2][temp],type='n')
text(data_new.mds$points[,1][temp], data_new.mds$points[,2][temp], 
     labels=(readdata$Region)[temp],col=readdata$Channel[temp])

