
print "hey it is reloded"
NOTICE = "GST applied from 1 July 2107"
GDP = 19.5

def bill(units, rate):
	if units >= 500:
		bill = units*rate*1.18
	else:
		bill = units*rate*1.12
	return bill

def speed(distance, time):
	print "speed is : ",distance/time
