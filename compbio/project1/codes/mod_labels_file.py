# -*- coding: utf-8 -*-
"""
Created on Tue Mar  7 18:51:58 2017

@author: zhy
"""

#This file is edited by Haoyu Zhao
"""This file aims to slightly modify the .star file to load the labels better.
The modification includes deleting the first several lines that include the 
string.
"""

def main():
    string1 = "./labels/stack_0"
    string2 = "_lowpass_2x_SumCorr_manual_lgc.star"
    
    i = 100
    while(i < 161):
        i += 1
        if i == 105:
            continue
        filename = string1 + str(i) + string2
        f = open(filename, "r")
        f1 = open("./labels/" + str(i), "w")
        j = 0
        for line in f:
            j += 1
            if j < 10:
                continue
            f1.write(line)
    
if __name__ == "__main__":
    main()