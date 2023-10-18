books = []

for item in range(1,10):
	books.append(raw_input("Enter book name : "))

print books
count = 0
findbook = raw_input("Enter find book name : ")
for item in books:
	if item == findbook:
		count = 1
		break
if count == 1:
	print "book found"
else:
	print "book not found"
	




	