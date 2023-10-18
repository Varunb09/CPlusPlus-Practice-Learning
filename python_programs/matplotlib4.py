from matplotlib import pyplot as plt
import numpy as np


x = np.arange(1,13,dtype='i1')
y = []

p = input("Enter principle ammount : ")
r = input("Enter rate : ")
t = input ("Enter time : ")
interest = (p*r*t)/100
sum = 0
num = 1
while num <= 12:
	sum = interest
	y.append(sum)
	sum = sum + interest
	num += 1

print y 


# plt.figure("Enrollment graph")
# plt.bar(x,y,color='r',label="College enrollment")
# plt.title("year wise enrollment")
# plt.xlabel("-----years-----")
# plt.ylabel("------enrollment-----")


plt.legend()
plt.savefig('enroll.png')
plt.show()
