# list is mutabble object which can contain any kind of data and it is growable in size
# Denoted by square brackets

marks = [98,97,68.50,45.70,34,78,23]  # marks represent list
for item in marks:
	print item

# list slicing
print 
print marks[3]
print marks[2:6]
print marks[3:]
print marks[:7]

# assigning in list
print
#  marks[8] = 1995    # index error as 
marks[4] = 1995  # update value of existing address
print marks
marks.append(1995)   #append new value at end of list
print marks