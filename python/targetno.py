import random

targetNum=random.randint(0,10)

for everyattempt in range(1,4):
    guessedNum =int(raw_input("guess number"))
    if (targetNum ==guessedNum):
        print"you won"
        break
    else:
        if everyattempt==3:
            print"you lost target number was %d"%(targetNum)
        else:
            print"try again"




