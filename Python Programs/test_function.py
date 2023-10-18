# unit test function
# Complilation statement : python -m unittest test_function
import unittest
from functions import bill

class TestFun(unittest.TestCase):
	"test class to test fun module"

	def test_bill(self):
		"method to test bill function"
		self.assertEqual(bill(200, 5, 1.12), 1120)
		self.assertEqual(bill(200, 5, 1.18), 1180)

	def test_types(self):
		self.assertRaises(TypeError,bill,"sevenfive",5,1.12)
		self.assertRaises(TypeError,bill,5+6j,5,1.12)
		
		