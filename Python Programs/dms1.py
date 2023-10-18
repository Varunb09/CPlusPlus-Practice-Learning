
units = input("Enter No. of units : ")

if units >= 500:
	bill = units*5.0*1.18
	print "pay bill with GST is : ",bill
else:
	bill = units*3.0
	print "pay bill without GST is = ",bill