#find numeric in data
data = "Techno India NJR @ 12345 will close by 2020"
for item in data:
	if item not in "0123456789":
		continue
	print item		



# print without space
for alp in data:
	if alp== " ":
		continue
	else:
		print alp
