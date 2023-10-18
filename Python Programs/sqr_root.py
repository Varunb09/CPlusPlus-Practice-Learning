import math

while True:
	num = input("Enter a num to calculate square root : ")
	if num >= 0:
		sqrt = math.sqrt(num)
		print "sqrt of %f is %f "%(num,sqrt)
	else:
		print "Bye Thank You :) "
		break