# print Character from a to z  using ascii value
for item in range(97,123,1):
	print "%c"%item 


print "\n"


# print Character from A to Z
for item in range(65,91,1):
	print chr(item)


# print user interst character 
# ord  read ascii value of the input character
start = raw_input("Enter starting alphabet : ")
end = raw_input("Enter end alphabet : ")
for item in range(ord(start), ord(end)+1):
	print chr(item)
