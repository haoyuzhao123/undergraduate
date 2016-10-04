import Simulator as S

sim = S.Simulator(0)
sim.write("in.txt", 0)
for i in range(2000):
	sim.executeOneStep()
	#sim.printRegister()
	#sim.printMemory()

#sim.printMemory()
