class course:
	def __init__(self, cc, ct, cf):
		self.CCode = cc
		self.CTitle = ct
		self.CFees = cf

	def showcourse(self):
		print "course Ccode : ",self.Ccode
		print "course CTitle : ",self.CTitle
		print "course CFees: ",self.CFees
		