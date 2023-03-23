from matplotlib import pyplot as plt
import numpy as np
print("h")

time = np.arange(0,3600,30)
distan = np.arange(0,1000,100)
print(len(distan))
walk = [0,80,160,240,320,400,480,550,620,700]
board = [20,40,60,80,100,120,140,160,180,200]
plt.plot(distan, walk)
plt.plot(distan,board)
plt.show()



