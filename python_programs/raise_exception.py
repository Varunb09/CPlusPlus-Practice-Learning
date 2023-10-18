# Raise must be with try-except otherwise it won't be able to raise exception

def bill(units, rate):
	if type(units) not in [int,float]:
		te = TypeError("units must be numeric")
		raise te
	if units < 0 :
		ve = ValueError("units must be numeric")
		raise ve
	pay = units*rate*1.18
	print "Please pay bill is : ",pay

names = ["Techno", 89, 56.90, 120, "Udaipur"]
try:
	bill("hundred", 5)		# this will generate generic raise error
	no1 = input("Enter a no1 : ")
	no2 = input("Enter a no2 : ")	# this will generate error if string is input

	rs = no1/no2		# this will generate error if denominator is zero
	print names[6]		# this will generate error due to index error
	print "End of try"

except (SyntaxError) as se:
	print "Error 1 occured : ",se
except (ZeroDivisionError) as zde:
	print "Error 2 occured : ",zde
except (IndexError) as ie:
	print "Error 3 occured : ",ie
except (Exception) as ex:
	print "Error 4 occured : ",ex
else : 
	print "we are in else"


bill(500, 5)
print "End of Program"

