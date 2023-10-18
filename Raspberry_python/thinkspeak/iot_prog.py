import sys
import RPi.GPIO as pin
from time import sleep
import Adafruit_DHT
import urllib2
myAPI = "DQPHB4BHRT9B6MJC"

def getSensorData():
	RH, T = Adafruit_DHT.read_retry(Adafruit_DHT.DHT11, 27)
	return (str(RH), str(T) )

def main():
	print 'starting .....'
	baseURL = 'https://api.thingspeak.com/update?api_key=%s'  %myAPI
	while True:
		try:
			RH, T = getSensorData()
			req = urllib2.Request(url = baseURL +"&field1=%s&field2=%s" %(T, RH))
			f = urllib2.urlopen(req)
			print(f.read())
			print(T,RH)
			#f.close()
			sleep(5)
		except:
			print 'exiting.'
			break
#call main
if __name__== '__main__':
	main()
