import serial
from time import sleep
s = serial.Serial("/dev/ttyS0",9600)
s.isOpen()


while True:
	r = s.read()
	sleep(0.03)
	print(r)
