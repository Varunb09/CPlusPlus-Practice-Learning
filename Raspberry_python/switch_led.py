import RPi.GPIO as pin
import time
pin.setwarnings(False)
pin.setmode(pin.BOARD)
pin.setup(11,pin.OUT)
pin.setup(13,pin.IN)
while True:
	res = pin.input(13)
	if res==0:
		pin.output(11,pin.HIGH)
	else: 
		pin.output(11,pin.LOW)

