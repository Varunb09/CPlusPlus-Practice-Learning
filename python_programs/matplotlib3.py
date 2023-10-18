from matplotlib import pyplot as plt
import numpy as np

x = np.arange(2012,2018)
y = [45,55,35,75,95,40]

plt.figure("Enrollment graph")
plt.bar(x,y,color='r',label="College enrollment")
plt.title("year wise enrollment")
plt.xlabel("-----years-----")
plt.ylabel("------enrollment-----")


plt.legend()
plt.savefig('enroll.png')
plt.show()
