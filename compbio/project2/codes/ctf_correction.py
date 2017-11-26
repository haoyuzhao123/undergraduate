import numpy as np
import scipy as sp

#this file is created by Haoyu Zhao to calculate the ctf and thus correct the image by it
"""This file defines some physics constant and write the function of ctf, this code try to use 
the vectorization during the computation of the ctf at each pixel to accelerate the computing
performance"""

#the plank constant, eV * s
h = 4.13566743e-15

#the mass of an electron, kg
m = 9.10938215e-31

#the ratio of J and eV
rate = 1.602176462e-19

#the acceleration voltage, V
V = 300000

#Amplitude Contrast, no unit
Q = 0.100000

#the pixel size, the unit is angstrom
pixelsize = 100000

#the _lambda in the ctf
_lambda = h * rate / (np.sqrt(2 * m * rate *  float(V))) * 1e10

#the Cs, _rlnSphericalAberration, 2mm, 2*10^7 A
Cs = 2e7

def ctf(img,paras):
    img_size = img.shape[0]

    #the .star file parameters
    DefocusU = paras[0]
    DefocusV = paras[1]
    DefocusAngle = paras[2]
    
    delta_z0 = -(DefocusU + DefocusV) / float(2.0)
    delta_z1 = -(DefocusU - DefocusV) / float(2.0)
    theta0 = DefocusAngle / float(180) * np.pi * np.ones((img_size, img_size))
    
    #compute the spatial frequency of the img that pass in
    #this small segment of code that compute the spatial frequency is
    #copied and modified from mathworks.com
    Fs_x = 1.0 / float(pixelsize)
    Fs_y = 1.0 / float(pixelsize)

    dFx = Fs_x / float(img_size)
    dFy = Fs_y / float(img_size)

    #compute the spatial frequency by vectorization
    listx = range(1,img_size+1,1)
    listy = range(1,img_size+1,1)

    vecx = np.array(listx).reshape([1,-1])
    vecy = np.array(listy).reshape([-1,1])

    matx = dFx * np.kron(vecx, np.ones((img_size,1)))
    maty = dFy * np.kron(vecy, np.ones((1,img_size)))

    mats = np.sqrt(matx ** 2 + maty ** 2)
    mattheta = np.arctan2(maty, matx)

    #compute the delta_z(theta)
    delta_z_theta = delta_z0 + delta_z1 * np.cos(2 * (mattheta - theta0))

    #compute the gamma(s, theta)
    gamma = 2 * np.pi * ( - Cs * _lambda ** 3 * mats ** 4 / 4.0 + delta_z_theta * _lambda * mats ** 2 / 2.0)

    #compute the ctf tranformation function for the img
    ctf_func = -(np.sqrt(1 - Q ** 2) * np.sin(gamma) + Q * np.cos(gamma))

    print "tha max in ctf:" + str(np.max(ctf_func))
    print "tha min in ctf:" + str(np.min(ctf_func))
    print "tha mean in ctf:" + str(np.mean(ctf_func))

    return ctf_func

def ctf_correct(img, paras):
    """do the ctf correction using the function that calculated in the ctf function.
    this due to the fact that O = F^{-1}(frac{F(I)}{ctf}).
    """
    ctf_func = ctf(img, paras)
    flip_phase_ctf = np.abs(ctf_func)
    fft_img = np.fft.fft2(img)
    ctf_corrected = fft_img / flip_phase_ctf
    img_corrected = np.fft.ifft2(ctf_corrected)
    img_corrected = np.real(img_corrected)
    return img_corrected
