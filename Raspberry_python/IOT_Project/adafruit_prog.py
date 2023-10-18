import sys
from time import sleep
import Adafruit_DHT
import RPi.GPIO as pin
import time
import lcd_interface

#pin.setmode(pin.BCM)

while True:
	humidity, temperature = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, 27)
	print(temperature)
#	lcd_interface.lstr(int(temperature))
	print(humidity)
#	lcd_interface.lstr(humidity)

