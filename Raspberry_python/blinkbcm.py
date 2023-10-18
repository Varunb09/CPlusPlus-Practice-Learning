import RPi.GPIO as pin
import time
pin.setwarnings(False)
pin.setmode(pin.BCM)
pin.setup(17,pin.OUT)
while True:
	pin.output(17,pin.HIGH)
	time.sleep(1)
	pin.output(17,pin.LOW)
	time.sleep(1)
