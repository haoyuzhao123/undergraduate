import numpy as np

#This file is created by Hoayu Zhao
"""This code aims to proprocess the image data to let it has 
mean 0 and variance 1.
"""

def main():
    training_data = np.load("training_data.npy")
    mean = np.mean(training_data)
    #subtract the mean of the data
    training_data = training_data - mean * np.ones(training_data.shape)
    #compute the variance
    var = np.sum(np.sum(training_data ** 2))
    sd = np.sqrt(var)
    #make the variance to be 1
    training_data_processed = training_data / float(sd) * 1000.0
    np.save("training_data_processed.npy",training_data_processed)

if __name__ == "__main__":
    main()
