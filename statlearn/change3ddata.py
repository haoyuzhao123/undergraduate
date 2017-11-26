# -*- coding: utf-8 -*-
"""
Created on Wed May 24 12:50:53 2017

@author: zhy
"""

import numpy as np
import scipy as sp
import matplotlib

def float_equal(x,y):
    if np.abs(x-y) < 0.000001:
        return 1
    else:
        return 0

def compact_data(data):
    temp = 0
    temp_vec = np.zeros((0,23))
    i=0
    
    while i < data.shape[0]:
        j = 0
        temp = data[i][0]
        while j < 13:
            if i % 1000 == 0:
                print(i)
                
            if float_equal(temp, data[i][0]):
                temp_vec = np.vstack((temp_vec, data[i,:]))
                i += 1
                j += 1
            else:
                temp_vec = np.vstack((temp_vec, np.zeros((1,23))))
                j += 1
        
    data = temp_vec.reshape(-1,13,23)
    
    return data

def main():
    data = np.load('data.npy')
    data1 = compact_data(data)
    print(data1.shape)
                
if __name__ == '__main__':
    main()