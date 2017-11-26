# -*- coding: utf-8 -*-
"""
Created on Tue Mar  7 18:36:18 2017

@author: zhy
"""

#This file is edited by Haoyu Zhao
"""This file aims to generate the training and testing data and the labels 
that are needed in the machine learning algorithms."""

import numpy.random as npr
import numpy as np
from EMAN2 import *
import select_panel
import matplotlib.pyplot as plt

import img_processor

def is_near_to_particle(coord, centers):
    res = 0
    m = centers.shape[0]
    for i in range(m):
        if (np.abs(coord[0] - centers[i][0]) ** 2  + np.abs(coord[1] - centers[i][1]) ** 2) <= 324:
            res = 1
            return res
    return res
    
def are_near_to_particles(coords, centers):
    n = coords.shape[0]
    res = np.zeros((n,1))
    
    for i in range(n):
        coord = coords[i,:]
        res[i][0] = is_near_to_particle(coord, centers)
	
    print np.sum(res)
    
    return res

def generate_training_data():
    i = 100
    training_data = np.zeros((0,10000))
    training_labels = np.zeros((0,1))
    
    string1 = "./homework_data/train/stack_0"
    string2 = "_lowpass_2x_SumCorr.mrc"
    string3 = "./labels/"

    avr = np.zeros((100, 100))
    
    while(i < 141):
        i += 1
        if i == 105:
            continue
        filename = string1 + str(i) + string2
        img = EMData(filename,0)
        pixels = np.array(img.get_data_as_vector()).reshape(3710, 3710)
        new = img_processor.process_img(pixels, 2, 4)
        labels = np.loadtxt(string3 + str(i))
        labels = labels[:, [0,1]] / 2
        num = labels.shape[0]
        fluc = npr.random_integers(-2,2,[num,2])
        labels = labels + fluc
        print "processing image "+ str(i) 
        
        data, count = select_panel.select_panels_from_image(new, labels, 50)
        avr += np.sum(data, axis = 0).reshape(100, 100)
        training_data = np.vstack((training_data, data))
        y = np.ones((count,1))
        training_labels = np.vstack((training_labels, y))
        
        t = 400 - count
        rand_centers = npr.random_integers(60, 1800, [t,2])
        data, count = select_panel.select_panels_from_image(new, rand_centers, 50)
        training_data = np.vstack((training_data, data))
        y = are_near_to_particles(rand_centers, labels)
        training_labels = np.vstack((training_labels, y))
    
    np.save("training_data.npy", training_data)
    np.save("training_labels.npy", training_labels)
    np.save("avr.npy", avr)
    plt.cla()
    plt.gray()
    plt.imshow(avr)
    plt.savefig("avr.png")

if __name__ == "__main__":
    generate_training_data()
        
