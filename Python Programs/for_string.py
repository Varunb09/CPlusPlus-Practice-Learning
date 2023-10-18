# count number of vowels
str = "Techno India NJR Institute Of Technology"
vowels = 0
for item in str:
	if item in "aeiouAEIOU":
		vowels += 1

print "No of Vowels = ", vowels
							
#replace vowels with a number

str = "Techno India NJR Institute Of Technology"
str1 = ""
vowels = 0
count = 0
for item in str:
	if item in "aeiouAEIOU":
		vowels += 1
		str1 += 7		
	else:
		str1 += item

print "No of Vowels = ", vowels
print str1