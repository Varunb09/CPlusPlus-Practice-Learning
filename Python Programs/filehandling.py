# File  methods and operation
# File Create and writeting data
str = "Udaipur is going to be smart city @ 2020, there will be int. airport"
file = open('python.txt','w')
file.write(str)
# check and open python.txt created by the system call
file.close()
print "Written into file"


# File read operation
file = open('python.txt')
content = file.read()
print content
file.close()

#file attributes
print file.closed
print file.mode
print file.name