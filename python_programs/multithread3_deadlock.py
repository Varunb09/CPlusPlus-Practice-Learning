import threading
import datetime
class task(threading.Thread):
	def run(self):
		lock.acquire()
		if (threading.currentThread().getName() == "first"):
			self.task1()
			lock.release()
		else:
			self.task2()

	def task1(self):
		for c in range(2000):
			if c == 500:
				input("Enter to continue")
			print c 
	def task2(self):
		print "v2 start : ",datetime.datetime.now()
		file2 = open('thor_ragnarok.mp4')
		v2 = file2.read()
		file2.close()
		print "v2 end : ", datetime.datetime.now()

lock = threading.Lock()
t1 = task()
t2 = task()
t1.setName("first")
t2.setName("second")
t1.start()
t2.start()