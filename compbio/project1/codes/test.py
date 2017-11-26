
import numpy as np
import numpy.random as npr
import scipy.signal as sps
import matplotlib.pyplot as plt
from EMAN2 import *
import img_processor
import select_panel

def main():
	labels = np.loadtxt('./labels/114')
	labels = labels[:, [0,1]]
	img = EMData("/home/zhy/codes/pycode/undergraduate/compbio/homework_data/test/stack_0142_lowpass_2x_SumCorr.mrc",0)
	pixels = img.get_data_as_vector()
	pixels_vec = np.array(pixels)
	pixels_vec = pixels_vec.reshape(3710, 3710)
	pixels_vec_p = np.array(pixels_vec)

	#plt.scatter(labels[:,0], labels[:,1], s = 1, c = 'r')
	plt.gray()
	plt.imshow(pixels_vec_p)
	plt.savefig("test1.png")
	plt.cla()


	new = img_processor.process_img(pixels_vec_p, 2, 4)
	labels = labels / 2
	select_panel.select_panels_from_image(pixels_vec, np.array([[475,850]]), 50)
	#select_panel.select_panels_from_image(pixels_vec, np.array([[500,600]]), 200)
	plt.cla()	
	#plt.scatter(labels[:,0], labels[:,1], s = 1)
	#plt.scatter([500], [600], s = 1, c = 'r')
	plt.gray()
	plt.imshow(new)
	plt.show()
	plt.savefig("test.png")

if __name__ == "__main__":
	main()
