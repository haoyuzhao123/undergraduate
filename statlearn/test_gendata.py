# -*- coding: utf-8 -*-
"""
Created on Wed May 24 10:54:14 2017

@author: zhy
"""

import numpy as np
import scipy as sp
import matplotlib

def main():
    data = np.load('data.npy')
    values = np.load('values.npy')
    print(data[0][0] == data[1][0])
    print(data.shape)
    print(data[1:4,0:23])
    print(values[1:4])
    
if __name__ == '__main__':
    main()