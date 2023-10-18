import RPi.GPIO as pin
import time
import lcd_interface
pin.setwarnings(False)
pin.setmode(pin.BOARD)
led = (11,13,15)
pin.setup(led,pin.OUT)

from flask import Flask, render_template 
app = Flask(__name__)

@app.route('/')
def webserver_html():
	return render_template('webserver_html.html')




#@app.route('/bangalore')
#def bangalore():
#	return 'Hello bangalore'


@app.route('/redled_on')
def ron():
	pin.output(11,pin.HIGH)
	lcd_interface.lstr("red on")
	time.sleep(2)
	lcd_interface.command(0x01)
	return 'bye'

@app.route('/redled_off')
def roff():
	pin.output(11,pin.LOW)
	lcd_interface.lstr("red off")
	time.sleep(2)
	lcd_interface.command(0x01)
	return 'bye'

@app.route('/greenled_on')
def gon():
	pin.output(13,pin.HIGH)
	return 'bye'

@app.route('/greenled_off')
def goff():
	pin.output(13,pin.LOW)
	return 'bye'


@app.route('/blueled_on')
def bon():
	pin.output(15,pin.HIGH)
	return 'bye'

@app.route('/blueled_off')
def boff():
	pin.output(15,pin.LOW)
	return 'bye'


if __name__ == '__main__':
	app.run(debug = True, host = '0.0.0.0')
