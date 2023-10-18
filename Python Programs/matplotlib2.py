from matplotlib import pyplot as plt
import numpy as np

x1 = np.arange(1,11,dtype='i1')
y1 = x1*x1+5

x2 = np.arange(1,11,dtype='i1')
y2 = 2*x2-5

plt.figure("Equation graph",figsize = (6,6))
plt.plot(x1,y1,color='r',label="y=x2+5",linewidth=3)
plt.title("x,y value graph")
plt.xlabel("x number")
plt.ylabel("y values")

plt.plot(x2,y2,color='b',label="y=2x-5",linewidth=3)
plt.legend()
plt.show()
