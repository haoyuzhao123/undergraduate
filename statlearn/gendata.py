# -*- coding: utf-8 -*-
"""
Created on Wed May 24 10:34:42 2017

@author: zhy
"""

import numpy as np
import scipy as sp
import matplotlib
import csv

def readFile(filename):
    """this function is used to read the datas in the csv file
    """
    dataSet = []
    dataSetp = []
    values = []
    
    with open(filename, 'r') as csvfile:
        reader = csv.reader(csvfile)
        i = 0
        for row in reader:
            dataSet.append(row)
         
    print(len(dataSet))
    for i in range(1, len(dataSet)):
        dataSetp.append(dataSet[i])
        values.append(dataSet[i][23])
        if i % 1000 == 0:
            print(i)
            
    dataMatrix = np.array(dataSetp)
    dataSet = dataMatrix[:, 0:23]
    values = np.array(values)
    csvfile.close()
    np.save("data.npy",dataSet)
    np.save("values.npy",values)
    return dataSet, values
    
def readFile2(filename):
    my_data = np.genfromtxt(filename, delimiter=',')
    data = my_data[1:, 1:24]
    values = my_data[1:, 24]
    np.save("data.npy",data)
    np.save("values.npy",values)  
    return data,values

def main():
    readFile2("data3.csv")
    #correct()

if __name__ == "__main__":
    main()