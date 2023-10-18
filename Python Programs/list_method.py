names = ["ganesh" , "ritesh" , "varun" , "techno" , "narayan"]

print "list",names

names.append("shubham")
print "appended shubham list : ",names

names.count("varun")
print "count varun list : ",names.count("varun")

names.extend([700, 900])
print "extended 700,900 list : ",names

print "index narayan list : ",names.index("narayan")

names.insert(1,"anshul")
print "insert anshul list : ",names

names.pop(3)
print "pop 3rd element list : ",names

names.remove("shubham")
print "remove shubham list : ",names

names.sort()
print "sorted list : ",names

names.reverse()
print "reverse list : ",names

