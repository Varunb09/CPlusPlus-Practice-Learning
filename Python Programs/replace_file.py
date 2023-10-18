# lines = file.readlines()
## readlines read the line in file and return a list of all content
# print lines

# line = ''
# for char in file.readlines():
# 	if char is ' ':
# 		line += '-'
# 	else:
# 		line += char

# print line
# file.close()


import os
file = open('content.txt')
#print os.stat('content.txt').st_size
file.read(100)
file.seek(5,2)
print file.tell()
file.close()
