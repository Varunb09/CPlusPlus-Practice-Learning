class Book:
	"a class to describe book detail" #doc string- it is optional
	def __init__(self,bc=1000,bt="techno",bp=1050.50): #constractor 
		self.Bcode = bc
	 	self.Btitle = bt
	 	self.Bprice = bp
	 	print "instance created"
	
	def showBook(self):
		print " -- Book details--"
		print "\nBook code :",self.Bcode
		print "\nBook title :",self.Btitle
		print "\nBook price :",self.Bprice

	def __del__(self):
		del self.Bcode
		del self.Btitle
		del self.Bprice
		print " INSTANCE DELETED"
def start():
	b1 = Book()
	b2 = Book(bc=1123)
	b3 = Book(bc=1233,bt = "python")
	b4 = Book(bc=1233,bt = "python",bp = 4566)
	b5 = Book(12332,"java",595)
	b1.showBook()
	b2.showBook()
	b3.showBook()
	b4.showBook()
	b5.showBook()

start()
