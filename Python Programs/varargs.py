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

