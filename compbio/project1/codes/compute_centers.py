# -*- coding: utf-8 -*-
"""
Created on Sun Mar 12 19:30:36 2017

@author: zhy
"""

#This file is edited by Haoyu Zhao
"""This file aims to select the center of each clusters."""

import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
import generate_data

def compute_the_final_output(matrix):
    try:
        kmeans = KMeans(n_clusters = 300).fit(matrix)
    except:
        kmeans = KMeans(n_clusters = 120).fit(matrix)
    return kmeans.cluster_centers_

def main():
    string3 = "./labels/"
    i = 141
    tot_res = 0
    tot_res_p = 0
    tot_labels = 0
    tot_cluster_centers = 0
    while i < 161:
        i += 1
        labels = np.loadtxt(string3 + str(i))
        labels = labels[:, [0,1]] / 2
        centers = np.load("center_"+str(i)+".npy")
        cluster_centers = compute_the_final_output(centers).astype(int)
        np.savetxt("cluster_centers_" + str(i) + ".star", 2 * cluster_centers);
        res = generate_data.are_near_to_particles(labels, cluster_centers)
        res_p = generate_data.are_near_to_particles(cluster_centers, labels)
        print "image " + str(i)
        print "#labels: " + str(labels.shape[0])
        print "#preds: " + str(cluster_centers.shape[0])
        print float(np.sum(res)) / float(labels.size / 2.0)
        print float(np.sum(res_p)) / float(cluster_centers.size / 2.0)
        tot_res += np.sum(res)
        tot_res_p += np.sum(res_p)
        tot_labels += float(labels.size / 2.0)
        tot_cluster_centers += float(cluster_centers.size / 2.0)
        plt.cla()
        plt.scatter(centers[:,0], centers[:,1], s = 0.2, c = "b")
        plt.scatter(cluster_centers[:,0], cluster_centers[:,1], s = 1, c = "r")
	plt.scatter(labels[:,0], labels[:,1], s = 1, c = "g")
        plt.savefig("final_centers_" + str(i) + ".png")
    
    print "recall = " + str(tot_res / float(tot_labels))
    print "precision = " + str(tot_res_p / float(tot_cluster_centers))
    
if __name__ == "__main__":
    main()
