emi = []
p = input("Enter principle ammount : ")
r = input("Enter rate : ")
t = input ("Enter time : ")
interest = (p*r*t)/100
sum = interest/12
num = 1
while num <= 12:
	emi.append(sum)
	sum = sum + sum
	num += 1

print emi