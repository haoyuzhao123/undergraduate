# -*- coding: utf-8 -*-
"""
Created on Sun Mar 12 09:31:30 2017

@author: zhy
"""

import numpy as np
import logistic
from EMAN2 import *
import matplotlib.pyplot as plt
import generate_data
import first_predict
import select_panel
import img_processor

def generate_second_data():
    c = 131
    training_second_data = np.zeros((0,10000))
    training_second_labels = np.zeros((0,1))
    
    training_data = np.load("training_data.npy")
    training_labels = np.load("training_labels.npy")
    classifier = logistic.log_reg()
    classifier.train(training_data, training_labels)
    
    string1 = "./homework_data/train/stack_0"
    string2 = "_lowpass_2x_SumCorr.mrc"
    string3 = "./labels/"
    
    while(c < 141):
        c += 1
        if c == 105:
            continue
        filename = string1 + str(c) + string2
        img = EMData(filename,0)
        pixels = np.array(img.get_data_as_vector()).reshape(3710, 3710)
        new = img_processor.process_img(pixels, 2, 4)
        labels = np.loadtxt(string3 + str(c))
        labels = labels[:, [0,1]] / 2
        centers = first_predict.first_classifier_predict(new, classifier, "all")
        y = generate_data.are_near_to_particles(centers, labels)
        print y.size
        temp, siz = select_panel.select_panels_from_image(new, centers, 50)
        ones = []
        for i in range(y.size):
            if (y[i] - 1)**2 < 0.01:
                ones.append(i)
                
        zeros = []
        for i in range(y.size):
            if (y[i] - 0)**2 < 0.01:
                zeros.append(i)
                
        if siz == y.size:
            print "the size matches."
        if len(ones) >= 500 and len(zeros) >= 500:
            print "ones and zeros >= 500"
            training_second_data = np.vstack((training_second_data, temp[ones[:500], :]))
            training_second_labels = np.vstack((training_second_labels, y[ones[:500], :]))
            training_second_data = np.vstack((training_second_data, temp[zeros[:500], :]))
            training_second_labels = np.vstack((training_second_labels, y[zeros[:500], :]))
        else:
            mini = min(len(ones), len(zeros))
            training_second_data = np.vstack((training_second_data, temp[ones[:mini], :]))
            training_second_labels = np.vstack((training_second_labels, y[ones[:mini], :]))
            training_second_data = np.vstack((training_second_data, temp[zeros[:mini], :]))
            training_second_labels = np.vstack((training_second_labels, y[zeros[:mini], :]))
    
    print training_second_data.shape
    
    np.save("training_second_data.npy", training_second_data)
    np.save("training_second_labels.npy", training_second_labels)

if __name__ == "__main__":
    generate_second_data()