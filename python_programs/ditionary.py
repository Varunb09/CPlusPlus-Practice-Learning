product = {'pen' : 45, 'paper' : 55, 'google' : 8.5, 'papuu' : 56, 101 : 'hello'}
print product

name = 'rohit'
marks = {name :98, 'gautam ': 97, 'varun' : 99}
print marks

# print element & key of dictionary
for key in product:
	print key, ':', product[key]

#updating
product['paper'] = 55
print product
#inserting
product['memory'] = 570
print product
#deleateing
del product['pen']

print product
