# nested loop example
row = 5
for r in range(1,row+1):
	col = 1
	while col <= r:
		print col,
		col += 1
	print 		# only print add new line like \n



row = 5
for r in range(1, row+1):
	#print chr(item)
	asciiU = 65
	asciiL = 97
	col = 1
	while col <= r:
		print chr(asciiU),chr(asciiL),
		asciiU += 1
		asciiL += 1
		col += 1
	print 