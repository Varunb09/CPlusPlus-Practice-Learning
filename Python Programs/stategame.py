import random
capitallist=['delhi','mumbai','guwahati','raipur','gandhinagar']
randomnum=random.randint(0,4)
randomcapital=(capitallist[randomnum])
caplen=len(randomcapital)
finalword=['_']*caplen
print randomcapital
attempt=10

while 1:
    print finalword
    randomguess=raw_input("enter char->")
    if randomguess in randomcapital:
        for everyletterindex in range(0,caplen):
            if randomguess==randomcapital[everyletterindex]:
                finalword[everyletterindex]=str(randomguess)
    else:
        attempt=attempt-1
    if '_' not in finalword:
        print "you won"
        break
    if attempt==0:
        print "you lost"
        break
    else:
        print "%d attempt left"%attempt



