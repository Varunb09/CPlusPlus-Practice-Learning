import random
print "please type only three alphabets of month"
mydict={1:'jan',2:'feb',3:'mar',4:'apr',5:'may',6:'jun',7:'jul',8:'aug',9:'sep',10:'oct',11:'nov',12:'dec'}
targetNum=random.randint(1,12)
for everyattempt in range(1,4):
    print "%s"%(mydict[targetNum])
    guessedmon =(raw_input("guess MONTH"))
    if (mydict[targetNum].upper() ==guessedmon.upper()):
        print"you won"
        break
    else:
        if everyattempt==3:
            print"you lost target MONTH was %s"%(mydict[targetNum])
        else:
            print"try again"



