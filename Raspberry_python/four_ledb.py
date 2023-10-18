import RPi.GPIO as pin
import time
pin.setwarnings(False)
pin.setmode(pin.BOARD)
led = (11,12,13,15)
val1 = (1,0,1,0)
val2 = (0,1,0,1)
pin.setup(led,pin.OUT)
while True:
	pin.output(led,val1)
	time.sleep(1)
	pin.output(led,val2)		
	time.sleep(1)

