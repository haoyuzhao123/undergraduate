# -*- coding: utf-8 -*-
"""
Created on Thu Jan  4 16:05:21 2018

@author: zhy
"""

#the constants for the whole program
class Const:
    #the batch_size for the mini-batch gradient descent
    batch_size = 100
    #the constant for the numerical accuraccy and stability
    epsilon = 1e-9
    #the constants for the loss functions
    m_plus = 0.9
    m_minus = 0.1
    lambda_val = 0.5
    #the constants for the regularization
    regularization_scale = 0.392
    
    #conv1 layer constants
    ker_size_conv = 9
    ker_output_conv = 256
    ker_strides_conv = 1
    
    #primary caps constants
    ker_size_pcaps = 9
    ker_output_pcaps = 32
    length_pcaps = 8
    ker_strides_pcaps = 2
    
    #digit caps constant
    length_dcaps = 16
    dcaps_size = 1152 #need to set manually
    
    #fully connected network
    size_fc1 = 512
    size_fc2 = 1024
    