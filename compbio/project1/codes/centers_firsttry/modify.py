#This file is edited by Haoyu Zhao
"""This file just aims to multiply the coordinates in the .star files by 2 because I forget to multiply it during the generation of the .star file"""

import numpy as np

string1 = "cluster_centers_"
string2 = ".star"

for i in range(142,162):
	filename = string1 + str(i) + string2
	newname = string1 + str(i) + "_mod" + string2
	star = np.loadtxt(filename)
	star = (2 * star).astype(int)
	np.savetxt(newname, star)
