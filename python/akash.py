count=0
myname="VARUN BHATNAGAR"
#myname=myname.upper()
print "%s"%(myname)
n=raw_input('which word you want to find')#.upper()
for x in myname:
    if(n.upper()==x.upper()):
        count=count+1
print " %s is available %d times"%(n,count)

