
emp = {}

for count in range(4):
	key = input("Enter emp key : ")
	name = raw_input("Enter emp name : ")
	#inserting new value
	emp[key] = name
print emp

search = raw_input("Enter name to find : ")
for key in emp:
	if search in emp[key]:
		print emp[key]
