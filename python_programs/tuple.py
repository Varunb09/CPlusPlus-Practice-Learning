# tuple is a seqence of immutable python object & represented by paranthesis

price = (120.50, 130.60, 124.00, 560.60)

print price
print type(price)
print price[0] # type return float or respective value for individual element
print price[1:4] #type return tuple 

print price[2:]
print price[:9]
#  print price[9]     this will generate exception of index error

for item in price:
	print item

#   price[2] = 890  # generate error as it is immutable it can'nt be modified

print len(price)

