# -*- coding: utf-8 -*-
"""
Created on Sun Mar 12 10:40:54 2017

@author: zhy
"""

#This file is edited by Haoyu Zhao
"""This file aims to test the second classifier."""

from sklearn.ensemble import RandomForestClassifier
import numpy as np

def main():
    training_second_data = np.load("training_second_data.npy")
    training_second_labels = np.load("training_second_labels.npy")
    
    td = training_second_data[:8000, :]
    tl = training_second_labels[:8000]
    cvd = training_second_data[8000:, :]
    cvl = training_second_labels[8000:]
    
    clf = RandomForestClassifier(n_estimators = 20)
    clf.fit(td,tl.ravel())
    print clf.score(cvd, cvl)
    pred_ones = 0
    total_ones = 0
    correct = 0
    for i in range(cvl.size):
        temp = clf.predict(cvd[i,:].reshape(1,10000))
        pred_ones += temp
        total_ones += cvl[i]
        if temp == cvl[i]:
            correct == 1
    
    print "pred_ones: " + str(pred_ones)
    print "total_ones: " + str(total_ones)
    print "precision: " + str(float(correct) / float(cvl.size))
        

if __name__ == "__main__":
    main()