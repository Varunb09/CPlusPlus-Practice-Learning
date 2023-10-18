import RPi.GPIO as pin
import time
import lcd_interface
pin.setwarnings(False)
pin.setmode(pin.BOARD)
led = (11,13)
pin.setup(led,pin.OUT)

from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
	return 'Hey varun this first web server program'

@app.route('/bangalore')
def bangalore():
	return 'Hello bangalore'


@app.route('/redled_on')
def blinkon():
	pin.output(11,pin.HIGH)
	lcd_interface.lstr("red on")
	time.sleep(2)
	lcd_interface.command(0x01)
	return

@app.route('/redled_off')
def blinkoff():
	pin.output(11,pin.LOW)
	lcd_interface.lstr("red off")
	time.sleep(2)
	lcd_interface.command(0x01)
	return

@app.route('/greenled_on')
def gon():
	pin.output(13,pin.HIGH)
	return

@app.route('/greenled_off')
def goff():
	pin.output(13,pin.LOW)
	return

if __name__ == '__main__':
	app.run(debug = True, host = '0.0.0.0')
