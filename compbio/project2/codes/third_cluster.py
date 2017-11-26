import numpy as np
import matplotlib.pyplot as plt
import functions
from functions import isequal

#This file is created by Haoyu Zhao

def main():
    print "third clustering"
    num_clusters = 36
    training_data = np.load("training_data_processed.npy")
    m = training_data.shape[0]
    #first_clustering_centers = np.load("first_clustering_centers.npy")
    #first_clustering_labels = np.load("first_clustering_labels.npy")
    second_clustering_centers = np.load("second_clustering_centers.npy")
    second_clustering_labels = np.load("second_clustering_labels.npy")

    #generate the clustering data for the second clustering.
    print "generating second clustering data"
#    second_training_data = np.zeros((0,6400))
#    for i in range(m):
#	t = int(round(first_clustering_labels[i]))
#	training_vec = training_data[i,:].reshape((1,-1))
#	if not isequal(first_clustering_labels[i],t):
#	    if isequal(first_clustering_labels[i],t+1):
#		t = t + 1
#	    elif isequal(first_clustering_labels[i],t-1):
#		t = t - 1
#	    else:
#		print "error! No equal integer!"
#	s = int(round(second_clustering_labels[i]))
#	if not isequal(second_clustering_labels[i],s):
#	    if isequal(second_clustering_labels[i],s+1):
#		s = s + 1
#	    elif isequal(first_clustering_labels[i],s-1):
#		s = s - 1
#	    else:
#		print "error! No equal integer!"
#	
#	if not t == -1:
#	    class_center_one = first_clustering_centers[t,:].reshape((1,-1))
#	    if not s == -1:
#		class_center_two = second_clustering_centers[s,:].reshape((1,-1))
#		class_center = np.vstack((class_center_one, class_center_two))
#	    else:
#		class_center = class_center_one
#	    eliminated = functions.eliminate_subspace(training_vec,class_center)
#	    second_training_data = np.vstack((second_training_data, eliminated))
#	elif not s == -1:
#	    class_center = second_clustering_centers[s,:].reshape((1,-1))
#	    eliminated = functions.eliminate_subspace(training_vec,class_center)
#	    second_training_data = np.vstack((second_training_data, eliminated))
#	else:
#	    second_training_data = np.vstack((second_training_data, training_vec))
#	if i % 100 == 0:
#	    print str(i) + " complete!"
    #clustering_centers = np.vstack((first_clustering_centers, second_clustering_centers))
    third_training_data = functions.eliminate_subspace(training_data, second_clustering_centers)
    print "generating complete!"

    labels = functions.runKMeans(third_training_data, num_clusters)
    classes = []
    for i in range(num_clusters):
	classes.append([])

    for i in range(m):
	classnum = labels[i]
	classes[classnum].append(i)

    refined_classes = []
    for i in range(num_clusters):
	if len(classes[i]) < 75:
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
	plt.savefig("./third_clustering/cluster_"+str(j)+".png")
    
    costJ = costJ / float(number_count)
    class_labels = functions.find_class(refined_classes, m)
    np.save("first_clustering_labels.npy", class_labels)
    np.save("first_clustering_centers", centers)
    print "the cost of this clustering is: " + str(costJ)
    print "third clustering complete"

if __name__ == "__main__":
    main()
