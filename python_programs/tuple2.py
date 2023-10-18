product = ("pen" , 120 , "pencil" , 25.50 , "google" , 780.90)
numeric = 0
for item in product:
	if type(item) in [int,float,str]:
		numeric += 1
print "No in tuple : ", numeric	