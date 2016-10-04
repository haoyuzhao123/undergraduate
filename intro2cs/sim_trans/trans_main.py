# -*- coding: utf-8 -*-
"""
Created on Mon Oct  3 23:32:18 201

@author: zhy
"""

import Translator as T

def main():
    trans = T.Translator()
    trans.loadfile("pseudo.txt")
    trans.decode()
    
if __name__ == '__main__':
    main()