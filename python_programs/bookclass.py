#claas andobject
class Book:
	"a class to describe book detail" #doc string- it is optional

	def setBook(self,bc,bt,bp):
		self.Bcode = bc
		self.Btitle = bt
		self.Bprice = bp

	def showBook(self):
		print " -- Book details--"
		print "\nBook code :",self.Bcode
		print "\nBook title :",self.Btitle
		print "\nBook price :",self.Bprice

b1 = Book()

b1.Bpages =1223 #new instance variable creation
b1.setBook(1001,"java",456)
b1.showBook()

b2 = Book()

b2.setBook(1002,"python",797)
b2.showBook()
