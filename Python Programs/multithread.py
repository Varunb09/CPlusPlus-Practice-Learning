# this example run sequentially therefore we add multi threading to this program
# class task1:
# 	def run(self):
# 		for c in range(2000):
# 			if c == 500:
# 				input("Enter to continue")
# 			print c 


# class task2: 
# 	def run(self):
# 		num = 1
# 		while(num <= 1000):
# 			print num
# 			num += 0.1

# t1 = task1()
# t1.run()

# t2 = task2()
# t2.run()


## this program uses multithreading

# task class is created in which two task are threaded 
import threading
class task(threading.Thread):
	def run(self):
		if (threading.currentThread().getName() == "first"):
			self.task1()
		else:
			self.task2()

	def task1(self):
		for c in range(2000):
			if c == 500:
				input("Enter to continue")
			print c 
	def task2(self):
		num = 1
		while(num <= 1000):
			print num
			num += 0.1

t1 = task()
t2 = task()
t1.setName("first")
t2.setName("second")
t1.start()
t2.start()