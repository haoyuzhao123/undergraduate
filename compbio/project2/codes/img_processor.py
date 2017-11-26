# -*- coding: utf-8 -*-
"""
Created on Mon Mar  6 19:06:22 2017

@author: zhy
"""

#This file is edited by Haoyu Zhao in project 1
#In this project, i just comment out some of the codes in this file that are not related to this project
"""This module is served as processing the raw cryo-EM image at first.
We do not use very complex algorithms, we just pool the image first and then
use a gaussian kernel to smooth the image. Last put the value of the pixels in
[0,1]."""

import numpy as np
from scipy.ndimage import gaussian_filter
import matplotlib.pyplot as plt

def pool(poolDim, img):
    Dim1 = img.shape[0]
    Dim2 = img.shape[1]
    poolDim1 = img.shape[0] / poolDim
    poolDim2 = img.shape[1] / poolDim
    size = img.size
    img = img.reshape((size/poolDim, poolDim))
    temp = np.sum(img, 1)
    temp.shape = Dim1, poolDim2
    temp = temp.transpose()
    temp = temp.reshape(size/(poolDim**2), poolDim)
    temp = np.sum(temp, 1)
    temp.shape = poolDim2, poolDim1
    return temp.transpose() / float(poolDim**2)

def process_img(img, poolDim, sigma):
    temp = img

    temp = pool(poolDim, temp)
    #temp = gaussian_filter(temp, sigma)
    #matmax = np.max(temp)
    #matmin = np.min(temp)
    #print "max of the image is " + str(matmax)
    #print "min of the image is " + str(matmin)
    #temp = (temp - matmin*np.ones(temp.shape)) / (matmax - matmin)
    print "complete processing image"
    
    return temp
