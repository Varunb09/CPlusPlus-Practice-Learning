import serial
import time
s = serial.Serial("/dev/ttyS0",9600)
s.isOpen()

while True:
	a = "cranes"
	s.write(a)
	print(a)
	time.sleep(1)
