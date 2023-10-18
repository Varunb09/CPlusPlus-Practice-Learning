import re
# ^ represent starting point
# $ represent end point
regex = re.compile('^\d{10}$')

mobno = raw_input("Enter mob no : ")

result = regex.match(mobno)

if result:
	print "valid no"
else:
	print "invalid no"