import lcd_interface
import time
dt = raw_input("Enter data:")
lcd_interface.lstr(dt)
time.sleep(2)
lcd_interface.command(0x01)
