import sys
from time import sleep
import Adafruit_DHT
import urllib2
myAPI = "PFN1U8E2E3FA7U7Z"


def main():
	print 'starting .....'
	baseURL1 = 'https://api.thingspeak.com/channels/501752/fields/1/last?api_key=PFN1U8E2E3FA7U7Z'
	baseURL2 = 'https://api.thingspeak.com/channels/501752/fields/2/last?api_key=PFN1U8E2E3FA7U7Z'
	while True:
		try:
			f = urllib2.urlopen(baseURL1)
			st = f.read()
			print(st)
			t = float(st)
			if t > 30 : 
				print('hot')
			else :
				print('cold')
			f.close()
			sleep(5)
		except:
			print 'exiting.'
			break



		try:
			f = urllib2.urlopen(baseURL2)
			st = f.read()
			print(st)
			t = float(st)
			if t > 80 : 
				print('humid')
			else :
				print('normal')
			f.close()
			sleep(5)
		except:
			print 'exiting.'
			break
#call main
if __name__== '__main__':
	main()
