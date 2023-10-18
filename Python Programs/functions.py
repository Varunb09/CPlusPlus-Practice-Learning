# function defenation
## def <function>([parameters]):
##		"function_doc_strin"
##		function suite
## 		return[expression]


def bill(units,rate,gst=1.12):
	"function to calculate GST bill"
	# Exception handling basics
	#if type(units) not in [int, float]:
	#	raise TypeError("value must be type of numerics")
	#
	if units >= 500:
		gst = 18
		bill_amount = units*rate*gst
	else:
		bill_amount = units*rate*gst

	return bill_amount		## Function return
# Reqiured argument in calling funtion
pay = bill(1200,5)		## Function Calling
print "please pay bill amount : ", pay
# Keyword Arguments
pay = bill(rate = 4, units = 500)
print "please pay bill amount : ", pay
# Over-rides Default arguments given as gst=1.18
pay = bill(rate = 4, units = 500,gst=1.18)
print "please pay bill amount : ", pay
# Variable Length Arguments Example
# args can contain any number of arguments
#label contain title
def gamescore(label, *args):
	gs = 0
	for num in args:
		gs += num 
	print "Game Score is : ",gs

gamescore("Cricket", 70, 89, 90)
gamescore("Cricket")
gamescore("Cricket", 70.90, 67.90, 90.65, 45.2)

