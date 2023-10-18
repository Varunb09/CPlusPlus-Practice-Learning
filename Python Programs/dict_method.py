dict1 = {'pen' : 45, 'paper' : 55, 'google' : 8.5, 'papuu' : 56}
dict3 = {105:'shubham', 155:'jaipur', 206:'bangalore'}
print "dictionary",dict1


dict2 = dict1.copy()
print "dict copy : ",dict2

dict3.fromkeys('12345',100)
print "new dict from key : ",dict3.fromkeys('12345',100)

dict1.get('pen')
print "get pen : ",dict1.get('pen')

dict1.has_key('google')
print "has_key google : ",dict1.has_key('google')

dict1.items()
print "items: ",dict1.items()

dict1.keys()
print "keys : ",dict1.keys()

dict1.setdefault('anshul',77)
print "setdefault : ",dict1

dict1.update({'piyush':50})
print "update : ",dict1

dict1.values()
print "values: ",dict1.values()

dict1.clear()
print "dict : ",dict1