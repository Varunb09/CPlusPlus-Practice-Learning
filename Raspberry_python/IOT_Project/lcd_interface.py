import RPi.GPIO as pin
import time
pin.setwarnings(False)
pin.setmode(pin.BOARD)
dataline = (32,23,19,21,24,26,31,29)
rs = 3
enable = 5


def initlcd():
	pin.setup(dataline,pin.OUT)
	pin.setup(rs,pin.OUT)
	pin.setup(enable,pin.OUT)
	command(0x38)
	command(0x0e)
	command(0x01)
	command(0x80)
	return

def command(cmd):
	"lcd command function"
	for i in range(8):
		if cmd & (1<<i):
			pin.output(dataline[7-i],pin.HIGH)
		else:
			pin.output(dataline[7-i],pin.LOW)	
	pin.output(rs,0)
	pin.output(enable,1)
	time.sleep(0.001)
	pin.output(enable,0)
	return

def data(dt2):
	"data function"
	for i in range(8):
		if dt2 & (1<<i):
			pin.output(dataline[7-i],pin.HIGH)
		else:
			pin.output(dataline[7-i],pin.LOW)	
	pin.output(rs,1)
	pin.output(enable,1)
	time.sleep(0.001)
	pin.output(enable,0)
	return

def lstr(dt1):
	for j in range(len(dt1)):
		data(ord(dt1[j]))
	return

initlcd()
#while True:
	#x= raw_input("Enter 1 for command and 2 for data")
	#def switcher(x):
	#	switcher = {
	#		1: 
	#cd = raw_input("Enter command")
	#command(cd)
	#		2: 
	##dt = raw_input("Enter data:")
	##lstr(dt)
	##time.sleep(2)
	##command(0x01)
	#	}
	#	print switcher.get(x, "invalid")

			
				
		

