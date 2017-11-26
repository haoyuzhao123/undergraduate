import numpy as np
import scipy as spy
import numpy.random
import csv
import matplotlib.pyplot as plt

def palmer(data, input_vec):
	time = data[:,0].reshape(10,1)
	ref = data[:,1].reshape(10,1)
	m = data.shape[0]
	n = data.shape[1]

	values = 0
	if n == 3:
		values = data[0,2]

	valid = time_slice(time)
	pred = sum(valid * (input_vec[0][0] * 10 ** (input_vec[1][0] * ref)))
	if n == 2:
		return pred

	cost = np.abs(pred - values)

	da =sum(valid * 10 ** (input_vec[1] * ref))
	db =sum(valid * 10 ** (input_vec[1] * ref) * ref * input_vec[0] * np.log(10))

	if cost > values:
		grad_input_vec = np.zeros((2,1))
		grad_input_vec[0][0] = da / 200000
		grad_input_vec[1][0] = db / 200000
	else:
		grad_input_vec = np.zeros((2,1))
		grad_input_vec[0][0] = -da / 200000
		grad_input_vec[1][0] = -db / 200000

	return (grad_input_vec, cost)

def palmer_parallel(data_3d, input_vec):
	input_primer = input_vec
	m = data_3d.shape[0]
	n = data_3d.shape[2]
	grad_input_vec = np.zeros((2,1))
	cost = 0
	count = 0

	if n == 2:
		pred_vec = np.zeros((m,1))

		for i in range(m):
			data = data_3d[i,:,:]
			pred_vec[i][0] = palmer(data, input_vec)

		return pred_vec

	for i in range(m):
		data = data_3d[i,:,:]
		grad_input_vecp, costp = palmer(data, input_primer)
		grad_input_vec = grad_input_vec + grad_input_vecp
		cost = cost + costp
		count = count + 1

	grad_input_vec = grad_input_vec / count
	cost = cost / count

	return grad_input_vec, cost

def time_slice(time):
	m = len(time)

	valid_time = np.zeros((m+2,1))
	for i in range(len(valid_time)):
		if i == 0:
			valid_time[i] = -time[0]
		elif i == len(valid_time)-1:
			valid_time[i] = 120-time[i-2]
		else:
			valid_time[i] = time[i-1]

	temp = (valid_time[0:m+1] + valid_time[1:m+2])/2
	valid = temp[1:m+1] - temp[0:m]

	return valid

def minFuncSGD(alpha, initialInput, training_data, epochs, batch_size, initial_temp):
    res_prime = initialInput.reshape((2,1))
    m = training_data.shape[0]
    n = training_data.shape[2]
    numbers = np.array(list(range(0, m)))
    #setup the momentum
    mom = 0.3
    velocity = np.zeros(initialInput.shape)
    momIncrease = 15
    prev_cost = 10000
    #
    delta = 0.98
    T = initial_temp
    
    for i in range(epochs):
        np.random.shuffle(numbers)

        t = 0
        i = 0
        
        while (i < m):
            t = t + 1
            if t > momIncrease:
                mom = 0
            
            if m - i < batch_size:
                temp = numbers[i:]
                i = m
            else:
                temp = numbers[i:(i + batch_size)]
                i += batch_size
            
            back_up_res = res_prime
            back_up_velocity = velocity

            beta = 1
            res_prime = back_up_res
            res_prime = res_prime - beta * velocity
            small_data = training_data[temp ,:, :]
            grad, cost = palmer_parallel(small_data, res_prime)
            if cost < prev_cost:
            	prev_cost = cost
            	print(cost)
            	velocity = mom * velocity + alpha * grad
            else:
            	if np.exp((prev_cost - cost) / T) > np.random.random():
            		prev_cost = cost
            		print(cost)
            		velocity = mom * velocity + alpha * grad
            		prev_cost = cost
            	else:
            		res_prime = back_up_res
            		velocity = back_up_velocity * np.random.random()


            T = T * delta
            #print('the velocity')
            #print(velocity)
        
        alpha = float(alpha) / 1.25
    
    return res_prime

def readFile(filename):
    """this function is used to read the datas in the csv file
    """
    dataSet = []
    dataSetp = []
    labels = []
    with open(filename, 'r') as csvfile:
        reader = csv.reader(csvfile)
        i = 0
        for row in reader:
            dataSet.append(row)
          
    for i in range(0, len(dataSet)):
        dataSetp.append(dataSet[i])
        
    for i in range(0, len(dataSetp)):
        for j in range(0, len(dataSetp[i])):
            dataSetp[i][j] = float(dataSetp[i][j])
            
    dataMatrix = np.array(dataSetp)
    csvfile.close()
    return dataMatrix


def main():
	dataMatrix = readFile('data4.csv')
	dataSet = dataMatrix.reshape((-1,10,3))
	print(dataMatrix.shape)

	initialInput = [[0.03], [0.0625]]
	initialInput = np.array(initialInput)

	#divide the training and test set
	numbers = np.array(list(range(0, dataSet.shape[0])))
	np.random.shuffle(numbers)
	training_vec = numbers[0:8000]
	testing_vec = numbers[8000:]
	training_set = dataSet[training_vec,:,:]
	testing_set = dataSet[testing_vec,:,:]

	res_prime = [[0.03], [0.0625]]
	res_prime = np.array(initialInput)
	res_prime = minFuncSGD(0.1, initialInput, training_set, 30, 2000,0.1)
	print(res_prime)
	print('test the performance')
	minFuncSGD(0, res_prime, testing_set, 1, testing_set.shape[0],1)
	pred_vec = palmer_parallel(testing_set[:,:,0:2], res_prime)
	plt.cla()
	plt.scatter(testing_set[:,0,2], pred_vec, alpha = 0.1)
	x = range(120)
	plt.plot(x,x,color = 'red')
	plt.show()

if __name__ == '__main__':
	main()
