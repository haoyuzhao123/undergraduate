# -*- coding: utf-8 -*-
"""
Created on Tue Mar  7 20:34:01 2017

@author: zhy
"""

#This file is edited by Haoyu Zhao
"""This file implement a function to select a panel, the function has 
the parameters: the size of panel, which have the same length and width, and the 
centre of the panel, and the original image.
"""

import numpy as np
import matplotlib.pyplot as plt

def select_panels_from_image(img, centers, half_of_length):
    """the img is an n by n matrix, the centres is an m by 2 matrix,
    where each row denotes the coordinate of the center.
    """
    t = centers.size
    centers.shape = (t/2, 2)
    size = 4 * half_of_length**2
    m = centers.shape[0]
    output_vec = np.zeros((m,size))
    count = 0
    
    for i in range(m):
        y = centers[i][0]
        x = centers[i][1]
        x_low = int(x - half_of_length + 1)
        x_high = int(x + half_of_length + 1)
        y_low = int(y - half_of_length + 1)
        y_high = int(y + half_of_length + 1)
        panel = img[x_low:x_high, y_low:y_high]
        if panel.size != size:
            continue
	#plt.cla()
	#plt.gray()
	#plt.imshow(panel)
	#plt.savefig(str(i) + ".png")
        output_vec[count,:] = panel.reshape((1,size))
        count += 1
    
    return output_vec[:count,:], count
