class Book:
	Bpub = "Techno"
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
print Book.Bpub
Book.Bpub = "Microsoft"
print Book.Bpub
b1 = Book()
print b1.Bpub
b1.Bpub = "google"
print b1.Bpub
print Book.Bpub