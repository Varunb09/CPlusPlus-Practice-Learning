# convert into float
pa = float(raw_input("Enter principle amount : "))
# represent type of variable
# raw_input represent string input values
# input represent numeric input values
print type(pa)
time = input("Enter time : ")
rate = input("Enter rate : ")
interest = (pa*time*rate)/100

print "Interest is : ",interest
