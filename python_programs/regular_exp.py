# methods of regular expression
import re
print "match method output : "
input = "look hook pook book"
#result = re.match('[abcdefgh]',input)
# or
result = re.match('[a-h]ook',input)
if result:
	print result.group(0)
else:
	print "not found"
####

input1 = "hook pook book look"
result1 = re.match('[a-h]ook',input1)
if result1:
	print result1.group(0)
else:
	print "not found"

#########################
print "serch method output : "
input2 = "pook hook book look"
result2 = re.search('[a-h]ook',input2)
if result2:
	print result2.group(0)
else:
	print "not found"

###
print "3rd argument search method output : "
input3 = "pook Hook Book look"
# re.i represent case sensitive as 3rd argument of method as flag
result3 = re.search('[a-h]ook',input3,re.I)
if result3:
	print result3.group(0)
else:
	print "not found"

########################
print "find all output : "
input4 = "pook Hook Book look"
# re.i represent case sensitive as 3rd argument of method as flag
result4 = re.findall('[a-h]ook',input4,re.I)
for token in result4:
	print token
print

####