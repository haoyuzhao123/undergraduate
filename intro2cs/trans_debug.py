# -*- coding: utf-8 -*-
"""
Created on Mon Oct  3 18:25:24 2016

@author: zhy
"""

import Translator as T

trans = T.Translator()

trans.loadfile("in.txt")

print(trans.labels)
print(trans.pseudocode)
print(trans.tags)
print(trans.vars)

trans.decode()