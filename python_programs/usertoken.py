import re

input = raw_input("Enter input string")
print input

# finding all digits in string
digits = re.findall('[0-9]',input)
# finding all vowels in string
vowels = re.findall('[aeiou]',input,re.I)

print digits
print vowels