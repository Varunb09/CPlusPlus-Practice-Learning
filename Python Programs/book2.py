book = {}

for count in range(2):
	bcode = input("Enter book code : ")
	btitle = raw_input("Enter book title : ")
	bprice = input("Enter book price : ")
	temp = []
	temp.append(bcode)
	temp.append(btitle)
	temp.append(bprice)

	book[bcode] = temp

print book

value = input("Enter price to filter book : ")
for bcode in book:
	if book[bcode][2] >= value:
		print book[bcode]

