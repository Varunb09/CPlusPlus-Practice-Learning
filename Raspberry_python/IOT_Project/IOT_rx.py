import serial
import lcd_interface
from time import sleep
import sys
import RPi.GPIO as pin
import Adafruit_DHT
import urllib2

import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEText import MIMEText

fromaddr = "cranesiotstudent@gmail.com"
toaddr = "varunbhatnagar115@gmail.com"
msg = MIMEMultipart()
msg['From'] = fromaddr
msg['To'] = toaddr
msg['bcc'] = "varunb067@gmail.com"
msg['Subject'] = "RTC value from ARM 7"


s = serial.Serial("/dev/ttyS0",9600)
s.isOpen()
myAPI = "EL18AQZMRGWXMP21"


print 'starting .....'
baseURL = 'https://api.thingspeak.com/update?api_key=%s'  %myAPI
while True:
#	try:
	sample = s.read(1)
	if sample == 'R':
		r = s.read(8)
		sleep(0.03)
		print(r)
		msg.attach(MIMEText(r, 'plain'))
		server = smtplib.SMTP('smtp.gmail.com',587)
		server.ehlo_or_helo_if_needed()
		server.starttls()
		server.ehlo_or_helo_if_needed()
		server.login("cranesiotstudent@gmail.com","iotGatePass")
		text = msg.as_string()
		server.sendmail(fromaddr, toaddr, text)
	if sample == 'T':
		r2 = s.read(8)
		T = r2[2:4]
		L = r2[7]
		sleep(0.03)
		print(T,L)
		req = urllib2.Request(url = baseURL +"&field1=%s&field2=%s" %(T, L))
		f = urllib2.urlopen(req)
		#print(f.read())
		#print(T,L)
		f.close()
#		sleep(3)
#	except:
#		print 'exiting.'
#		break
#call main




