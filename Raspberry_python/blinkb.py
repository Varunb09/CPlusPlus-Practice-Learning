import RPi.GPIO as pin
import time
pin.setwarnings(False)
pin.setmode(pin.BOARD)
pin.setup(11,pin.OUT)
while True:
	pin.output(11,pin.HIGH)
	time.sleep(1)
	pin.output(11,pin.LOW)
	time.sleep(1)
