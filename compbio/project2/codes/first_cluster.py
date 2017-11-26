import numpy as np
import matplotlib.pyplot as plt
import functions

#This file is created by Haoyu Zhao

def main():
    print "first clustering"
    num_clusters = 36
    training_data = np.load("training_data_processed.npy")
    labels = functions.runKMeans(training_data, num_clusters)
    m = labels.shape[0]
    classes = []
    for i in range(num_clusters):
	classes.append([])

    for i in range(m):
	classnum = labels[i]
	classes[classnum].append(i)

    refined_classes = []
    for i in range(num_clusters):
	if len(classes[i]) < 100:
	    continue
	refined_classes.append(classes[i])
    
    number_count = 0
    for i in range(len(refined_classes)):
	number_count += len(refined_classes[i])
	#print "cluster " + str(i) + " has number of imgs: " + str(len(refined_classes[i]))

    centers = np.zeros((0,6400))
    costJ = 0.0    

    for j in range(len(refined_classes)):
	temp = training_data[refined_classes[j],:]
	num = temp.shape[0]
	classimg = np.sum(temp, axis = 0) / float(num)
	centers = np.vstack((centers,classimg))
	classimg_vec = np.kron(classimg,np.ones((num,1)))

	#compute the cost of this class
	cost_this_class = np.sum(np.sum((temp - classimg_vec) ** 2))
	print "this class has number: " + str(num) +" the average cost of the class is: " + str(cost_this_class / float(num))
	costJ += cost_this_class

	classimg = classimg.reshape((80,80))
	plt.cla()
	plt.gray()
	plt.imshow(classimg)
	plt.savefig("./first_clustering/cluster_"+str(j)+".png")
    
    costJ = costJ / float(number_count)
    class_labels = functions.find_class(refined_classes, m)
    np.save("first_clustering_labels.npy", class_labels)
    np.save("first_clustering_centers.npy", centers)
    print "the cost of this clustering is: " + str(costJ) 
    print "first clustering complete"

if __name__ == "__main__":
    main()
