marks = []
for item in range(1,10):
	marks.append(input("Enter marks : "))

print marks
Ac=0
Bc=0
Cc=0
Dc=0
Fc=0
Hc=0 
for item in marks:
	if item >= 75:
		Hc += 1
		print "honours "
	elif item >= 65:
		Ac += 1
		print "A grade"
	elif item >= 55:
		Bc += 1
		print "B grade"
	elif item >= 45:
		Cc += 1
		print "C grade"
	elif item >= 35:
		Dc += 1
		print "D grade"
	else :
		Fc += 1
		print "Fail"

print "honours are : ",Hc
print "A grade are : ",Ac
print "B grade are : ",Bc
print "C grade are : ",Cc
print "D grade are : ",Dc
print "Fail are : ",Fc


	