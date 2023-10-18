import re

input = """@ 2018 will be goood for dev because they will get package like
7798345353, jklzbfdkjfsk
udaipur will be smart @ 2025"""

print input

print "'\d','-',input : "
result = re.sub('\d','-',input)
print result 

print "'\d{2}','-',input : "
result1 = re.sub('\d{2}','-',input)
print result1 

print "'\d|[aeiou]','-',input : "
result2 = re.sub('\d|[aeiou]','-',input)
print result2 

print "'\d|[aeiou]','-',input, count = 6 : "
result3 = re.sub('\d|[aeiou]','-',input, count = 6)
print result3 
print