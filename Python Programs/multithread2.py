import threading
import datetime
class task(threading.Thread):
	def run(self):
		if (threading.currentThread().getName() == "first"):
			self.task1()
		else:
			self.task2()

	def task1(self):
		print "v1 start : ",datetime.datetime.now()
		file1 = open('how_its_made.mp4')
		v1 = file1.read()
		file1.close()
		print "v1 end : ", datetime.datetime.now()
	def task2(self):
		print "v2 start : ",datetime.datetime.now()
		file2 = open('thor_ragnarok.mp4')
		v2 = file2.read()
		file2.close()
		print "v2 end : ", datetime.datetime.now()

t1 = task()
t2 = task()
t1.setName("first")
t2.setName("second")
t1.start()
t2.start()