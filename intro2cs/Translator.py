# -*- coding: utf-8 -*-
"""
Created on Mon Oct  3 18:25:25 2016

@author: zhy
"""

#this is the program of machine languate translator

class Translator(object):
    def __init__(self):
        self.dictionary = {}
        self.labels = {}
        self.variable = {}
        self.tags = []
        self.vars = []
        self.pseudocode = []
        self.rule = {
            'LOAD_1' : '1',
            'LOAD_2' : '2',
            'STORE' : '3',
            'MOV' : '4',
            'ADD_INT' : '5',
            'ADD_FLO' : '6',
            'OR' : '7',
            'AND' : '8',
            'XOR' : '9',
            'ROT' : 'a',
            'JUMP' : 'b' }
            
    def clearAll(self):
        self.dictionary = {}
        self.labels = {}
        self.variable = {}
        self.tags = []
        self.vars = []
        self.pseudocode = []
        
    def loadfile(self, filename):
        file = open(filename)
        
        for line in file:
            line = line[:-1]
            if line[0] == '#':
                self.tags.append(line)
            elif line[0] == '%':
                self.vars.append(line)
            elif line[0] == '/' or line == "":
                continue
            else:
                line.split()
                self.pseudocode.append(line)
                
        file.close()
        
    def int2hexstring(self, a):
        string = str(hex(a))
        string = string[2:]
        if len(string) == 1:
            string = '0' + string
        return string
        
    def decode(self):
        machi_lang = []
        counter = 0
        for i in range(len(self.pseudocode)):
            if self.pseudocode[i][0:3] == 'def':
                string = self.pseudocode[i].split()
                string = string[0][3:]
                self.labels[string] = 2 * counter
            else:
                machi_lang.append([])
                thisline = (self.pseudocode[i]).split()
                machi_lang[counter].append(self.rule[thisline[0]])
                
                for j in range(1, len(thisline)):
                    string = thisline[j]
                    if len(string) <= 2:
                        machi_lang[counter].append(string)
                    elif string[0:3] == 'reg':
                        machi_lang[counter].append(string[-1])
                    elif string[0:3] == 'add':
                        machi_lang[counter].append(string[-2:])
                    elif string[0:3] == 'def':
                        machi_lang[counter].append(string[3:])
                        self.variable[string[3:]] = 2 * counter + 1
                
                counter += 1
        
        for i in range(len(machi_lang)):
            vec = machi_lang[i]
            for j in range(len(vec)):
                if vec[j][0] == '#':
                    vec[j] = self.int2hexstring(self.labels[vec[j]])
                elif vec[j][0] == '%':
                    vec[j] = self.int2hexstring(self.variable[vec[j]])
                    
        output = []
        
        for i in range(len(machi_lang)):
            string = ''
            vec = machi_lang[i]
            for j in range(len(vec)):
                string += vec[j]
            output.append(string)
            
        for i in range(len(output)):
            print(output[i])
