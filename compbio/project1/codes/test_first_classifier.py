# -*- coding: utf-8 -*-
"""
Created on Tue Mar  7 23:35:02 2017

@author: zhy
"""

#This file is edited by Haoyu Zhao
"""This file aims to make the training of the neural network an abstraction.
"""

import numpy as np
import logistic

def train_alg():
    training_data = np.load("training_data.npy")
    training_labels = np.load("training_labels.npy")
    
    td = training_data[:12000, :]
    cvd = training_data[12000:, :]
    tl = training_labels[:12000, :]
    cvl = training_labels[12000:, :]
    classifier = logistic.log_reg()
    classifier.train(td, tl)
    #classifier = nNet.nNet(0.3)
    #classifier.train(td,tl)
    print "training complete!"
    
    m = cvl.shape[0]
    count = 0
    sum_sum = 0.0
    for i in range(m):
        output = classifier.predict_input(cvd[i,:])
        sum_sum += output
        if output == int(cvl[i][0]):
            count += 1
	else:
	    print "pred = " + str(output) + ", label = " + str(cvl[i][0])
    print sum_sum
    print np.sum(cvl)
    
    print float(count) / float(m)

if __name__ == "__main__":
    train_alg()
