# -*- coding: utf-8 -*-
"""
Created on Wed Mar  8 01:38:36 2017

@author: zhy
"""

#This file is edited by Haoyu Zhao
"""This file implement a simple logistic regression for binary classification
"""

import numpy as np
import numpy.random as npr

def sigmoid(matrix):
    return 1/(1 + np.exp(-matrix))

def predict(input_vec, theta):
    p = input_vec.size
    input_vec = input_vec.reshape((1,p))
    one = np.ones((1,1))
    input_vec = np.hstack((one, input_vec))
    
    prob = sigmoid(input_vec.dot(theta))[0,0]
    #print "prob = " + str(prob)
    
    if prob > 0.8:
        return 1
    else:
        return 0

def comp_grad(inputs, theta, ys, _lambda):
    m = inputs.shape[0]
    ones = np.ones((m,1))
    inputs = np.hstack((ones, inputs))
    h = sigmoid(inputs.dot(theta))
    cost = - np.sum(np.sum(ys * np.log(h))) - np.sum(np.sum((1 - ys) * np.log(1 - h)))
    grad_theta = 1 / float(m) * inputs.transpose().dot(h - ys) + _lambda * theta
    #print grad_theta.transpose().dot(grad_theta)
    #print np.sum(inputs.transpose().dot(h - ys)) / m
    return grad_theta, cost/float(m)

def sgd(batch_size, alpha, theta, _lambda, training_data, y, epochs):
    m = training_data.shape[0]
    n = training_data.shape[1]
    numbers = np.array(list(range(0, m)))
    
    #setup the momentum
    mom = 0.5
    velocity = np.zeros(theta.shape)
    momIncrease = 20

    count = 0
    for i in range(epochs):
        count += 1
        np.random.shuffle(numbers)
        i = 0
        t = 0
        
        while (i < m):
            t = t + 1
            if t > momIncrease:
                mom = 0.9
            
            if m - i < batch_size:
                temp = numbers[i:]
                i = m
            else:
                temp = numbers[i:(i + batch_size)]
                i += batch_size
            
            small_data = training_data[temp, :].reshape(temp.size, n)
            small_y = y[temp]
            grad_theta, cost = comp_grad(small_data, theta, small_y, _lambda)

	    #print grad_theta.transpose().dot(grad_theta)

            #print cost
            
            velocity = mom * velocity + alpha * grad_theta

            theta = theta - velocity

        
        alpha = float(alpha) / 1.2
        print "epoch " + str(count) + " complete."
    
    return theta

class log_reg(object):
    def __init__(self):
        self.theta = npr.rand(10001,1) * 0.1 * 2 - 0.1
    
    def train(self, td, tl):
        theta = sgd(256, 0.1, self.theta, 0.001, td, tl, 20)
        self.theta = theta
    
    def predict_input(self, input_vec):
        return predict(input_vec, self.theta)
