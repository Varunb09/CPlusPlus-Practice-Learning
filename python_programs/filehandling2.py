import os

data = raw_input("Enter text to write into a file : ")

#opening in append mode
file = open('content.txt','a')
file.write(data)
file.close()
#os.stat provide the statistics of file such as file content size,time,etc
fileinfo = os.stat('content.txt')
# st_size represent the number of character in file or size of file
print fileinfo.st_size

file = open('content.txt')
sum =0 
for count in range(fileinfo.st_size):
	char = file.read(1)
	if char in "123456789":
		digit = int(char)
		sum += digit  

print  "sum of all digits in a file is : ",sum
file.close()