# string is a collection of character
# it is a immutable object
# can be represented by single, double, triple quotes
# String Special Character : +,*,[],[:],in,not in, r/R,%

str = "Udaipur City "
print str+" Rajasthan"
print str*3   #  * represent repetition of string
# string slicing
print str[4]
print str[3:7]
print str[:9]
print str[3:]

if "a" in str:
	print "available"
if "x" not in str:
	print "not available"

print "string is : %s" %str
# raw string
print r'\n Hi \t Hey'