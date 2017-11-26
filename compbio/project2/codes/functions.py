from sklearn.cluster import KMeans
import numpy as np
import matplotlib.pyplot as plt

#This file is edited by Haoyu Zhao
"""The codes in this file aims to privide the basic functions for the clustering procedure
in the mian program
"""

def runKMeans(matrix, num_clusters):
    print "starting to cluster the images"
    try:
	kmeans = KMeans(n_clusters = num_clusters).fit(matrix)
	print "clustering complete"
    except:
	print "clustering failed"
    return kmeans.labels_

def cosine(vec1,vec2):
    vec1 = vec1.reshape((vec1.size,1))
    vec2 = vec2.reshape((vec2,size,1))

    inner = vec1.transpose().dot(vec2)
    l1 = np.sqrt(vec1.transpose().dot(vec1))
    l2 = np.sqrt(vec2.transpose().dot(vec2))
    cosine = inner / (l1 * l2)
    return cosine 

def eliminate_subspace(data, matrix):
    """in this function we assume that the vector and the matrix that
    pass to the function is row vector and the row space of the matrix
    is the portion that we want to eliminate 
    """

    data = data.transpose()
    mat = matrix.transpose()
    projected = mat.dot(np.linalg.inv(mat.transpose().dot(mat))).dot(mat.transpose().dot(data))
    processed = data - projected
    return processed.transpose()

def find_class(twodlist,number_of_imgs):
    class_labels = -np.ones((number_of_imgs,1))
    for i in range(len(twodlist)):
	for j in range(len(twodlist[i])):
	    t = twodlist[i][j]
	    class_labels[t] = i
    return class_labels

def isequal(i,j):
    if (i-j)**2 < 0.0001:
	return True
    else:
	return False

