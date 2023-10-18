# variable global, local example
salary = 5000

def modify(bonus):
	# global keyword is used to make function local variable to global variable 
	global salary
	salary += bonus
	print "Total Salary is : ", salary

modify(5000)
print "Total Salary is : ",salary