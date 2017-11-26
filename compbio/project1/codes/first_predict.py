# -*- coding: utf-8 -*-
"""
Created on Sat Mar 11 22:02:07 2017

@author: zhy
"""

#This file is edited by Haoyu Zhao
"""This file contains the code to select the particles 
by the first classifier in the new EM-Data picture
"""

import numpy as np
import img_processor
import logistic
import generate_data
from EMAN2 import *
import matplotlib.pyplot as plt
from sklearn.ensemble import RandomForestClassifier
import select_panel

def inboard(pixels, i, j):
    s = pixels.shape[0]
    t = pixels.shape[1]
    if i >= 0 and j >= 0 and i < s and j < t:
        return True
    else:
        return False

def can_be_delete(pixels, i, j):
    dx = [0,1,0,-1,1,1,-1,-1]
    dy = [1,0,-1,0,1,-1,1,-1]
    res = True
    for t in range(4):
        if inboard(pixels, i + dx[t], j + dy[t]):
            if pixels[i + dx[t]][j + dy[t]] == 1:
                res = False
    return res
    
def corr(mata, matb):
    if mata.shape[0] != matb.shape[0] or mata.shape[1] != matb.shape[1]:
        print "the shape of the matrices should be the same"
    res = np.sum(np.sum(mata * matb)) / np.sqrt(float(np.sum(np.sum(mata ** 2)) * np.sum(np.sum(matb ** 2))))
    return res

def predict(img, classifier1, classifier2, opt):
    step = 5
    x = img.shape[1]
    y = img.shape[0]
    half_of_length = 50
    centers = np.zeros((0,2))
    centers_p = np.zeros((0,2))

    s = len(range(55,x-54,step))
    t = len(range(55,y-54,step))
    
    new = np.zeros((s,t))
    
    for i in range(55,x - 54,step):
        for j in range(55,y - 54,step):
            x_low = int(i - half_of_length + 1)
            x_high = int(i + half_of_length + 1)
            y_low = int(j - half_of_length + 1)
            y_high = int(j + half_of_length + 1)
            temp_img = img[y_low:y_high,x_low:x_high]
            if temp_img.size != 4 * half_of_length ** 2:
                continue
            output = classifier1.predict_input(temp_img)
            if output == 1:
                pred = classifier2.predict(temp_img.reshape(1,temp_img.size))
                #pred = 1
                if np.abs(pred - 1) < 0.01:
                    temp_p = np.array([[i,j]])
                    centers_p = np.vstack((centers_p, temp_p))
                    #new[(i - 55)/5][(j-55)/5] = 1
    if opt == "all":
        return centers_p
    if opt == "select":
        for i in range(s):
            for j in range(t):
                if can_be_delete(new, i, j):
                    new[i][j] = 0
    
    for i in range(s):
        for j in range(t):
            if new[i][j] == 1:
                temp = np.array([[5 * i + 55,5 * j + 55]])
                centers = np.vstack((centers, temp))
    
    return centers 

def main():
    string1 = "./homework_data/test/stack_0"
    string2 = "_lowpass_2x_SumCorr.mrc"
    string3 = "./labels/"
    
    training_data = np.load("training_data.npy")
    training_labels = np.load("training_labels.npy")
    classifier = logistic.log_reg()
    classifier.train(training_data, training_labels)
    
    training_second_data = np.load("training_second_data.npy")
    training_second_labels = np.load("training_second_labels.npy")

    clf = RandomForestClassifier(n_estimators = 20)
    clf.fit(training_second_data, training_second_labels.ravel()) 
    
    for i in range(161,162):
        filename = string1 + str(i) + string2
        img = EMData(filename, 0)
        pixels = np.array(img.get_data_as_vector()).reshape(3710, 3710)
        new = img_processor.process_img(pixels, 2, 4)
        labels = np.loadtxt(string3 + str(i))
        labels = labels[:, [0,1]] / 2
        centers = predict(new, classifier, clf, "all")
        np.save("center_" + str(i) + ".npy", centers)
        
        res = generate_data.are_near_to_particles(labels, centers)
        res_p = generate_data.are_near_to_particles(centers, labels)
        print "image " + str(i)
        print "#labels: " + str(labels.shape[0])
        print "#preds: " + str(centers.shape[0])
        print float(np.sum(res)) / float(labels.size / 2.0)
        print float(np.sum(res_p)) / float(centers.size / 2.0)
        
               
	#plt.cla()
        #plt.scatter(centers[:,0], centers[:,1], s = 0.2)
        #plt.scatter(labels[:,0], labels[:,1], s = 1, c = "r")
        #plt.gray()
        #plt.imshow(new)
        #picname = str(i) + ".png"
        #plt.savefig(picname)
        #plt.cla()
        #plt.gray()
        #plt.imshow(new)
        #picname = str(i) + "_processed.png"
        #plt.savefig(picname)

if __name__ == "__main__":
    main()
        
