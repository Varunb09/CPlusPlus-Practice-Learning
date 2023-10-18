# Exception handling example
# if exception occur in try block it moves to except and raise user defined or 
# standard exception handling
def bill(units, rate):
	pay = units*rate*1.18
	print "Please pay bill is : ",pay

names = ["Techno", 89, 56.90, 120, "Udaipur"]
try:
	no1 = input("Enter a no1 : ")
	no2 = input("Enter a no2 : ")	# this will generate error if string is input

	rs = no1/no2		# this will generate error 
	print names[6]		# this will generate error
	print "End of try"
# 1st method 
#except :
#	print "Error occured"

## here exception handeled by standard exception classes
# 2nd method 
#except Exception as ex:
# 	print "Error occured : ",ex

# 3rd method
#except (SyntaxError, ZeroDivisionError, IndexError, Exception) as ex:
#	print "Error occured : ",ex

# 4th method
except (SyntaxError) as se:
	print "Error 1 occured : ",se
except (ZeroDivisionError) as zde:
	print "Error 2 occured : ",zde
except (IndexError) as ie:
	print "Error 3 occured : ",ie
except (Exception) as ex:
	print "Error 4 occured : ",
else : 
	print "we are in else"


bill(500, 5)
print "End of Program"

