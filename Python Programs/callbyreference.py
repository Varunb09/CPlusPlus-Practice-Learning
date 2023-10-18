#mutable type will bydefault global
# immutable objet does not support call by reference



# ----------------  call by value ------------------
# marks = [10,40,50]

# def updateMarks(temp):
# 	marks.append(temp)
# 	# marks which is list and list is mutable thus its bydefault global thus no need of writing like
# 	# global marks


# 	print "\nInside :",marks

# updateMarks(30)
# print "\nOutside :",marks

# --------------- call by reference--------------------marks = [10,40,50]

def updateMarks(temp):
	marks.append(70)
	print "\nInside :",marks

updateMarks(marks)
print "\nOutside :",marks

marks = [10,40,50]

def updateMarks(temp):
	marks.append(70)
	print "\nInside :",marks

updateMarks(marks)
print "\nOutside :",marks

# #- ---------------------  immutable call by reference ----------

# marks = [10,40,50]

# def updateMarks(temp):
# 	temp = 20
# 	marks.append(temp)
# 	print "\nInside :",marks


# tem = 10
# updateMarks(tem)
# print tem
# print "\nOutside :",marks




