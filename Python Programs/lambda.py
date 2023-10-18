# lambda is one line function in which at a time def + arguments are passed
# Anonymous Function
Interest = lambda pa,rate,time:pa*rate*time/100

print "Interest with required argument is : ", Interest(10000,10,3)
print "Interest with keyword argument is : ", Interest(rate = 10,time = 4,pa = 30000)
