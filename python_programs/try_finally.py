# Try - Finally Example
# statement in finally are always executed
# if file is not closed after exception occur then file resource can be hacked 
# therefore resources should be realesed if any used in program
# finally used with clean up codes
# else block can be used with try

try:
	file = open('content.txt')
	content = file.read()
	print "result : ",70/0
	file.close()
	print "End of try"

except (Exception) as ex:
	print "Error occured : ",ex
# if finally is not used then file is not closed and we can access file content
finally :
	file.close()
	print "file closed"

# Accessing file content
# file.seek(0,0)   # this will generate error as file closed by finally
print file.read()
print "End of Program"