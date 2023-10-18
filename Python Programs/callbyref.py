# call by refrence example
# when ever we pass mutable object in function then it is defined as call by refence
# immutable object does not support call by refence
marks = [90,80,45]

def updateMarks(temp):
	temp.append(50)
	print "Inside",temp

updateMarks(marks)
print "Outside : ",marks
