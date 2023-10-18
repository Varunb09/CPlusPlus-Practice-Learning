tttboard=range(1,10)
print tttboard[0:3]
print tttboard[3:6]
print tttboard[6:]
while 1:
    for everychance in range(0,9):
        if everychance%2==0:
            loc=int(raw_input("user-1 Enter location :) "))
            mark = 'O'
        else:
            loc=int(raw_input("user-2 Enter location :) "))
            mark = 'X'

        tttboard[loc-1]=mark

        print tttboard[0:3]
        print tttboard[3:6]
        print tttboard[6:]

        if tttboard[0]==tttboard[1] and tttboard[1]==tttboard[2]:
            if tttboard[0]=='O':
                print "user-1 wins :) "
                break
            elif tttboard[0]=='X':
                print "user-2 wins :) "
                break
        if tttboard[3]==tttboard[4] and tttboard[4]==tttboard[5]:
            if tttboard[3]=='O':
                print "user-1 wins :) "
                break
            elif tttboard[3]=='X':
                print "user-2 wins :) "
                break
        if tttboard[6]==tttboard[7] and tttboard[7]==tttboard[8]:
            if tttboard[6]=='O':
                print "user-1 wins :) "
                break
            elif tttboard[6]=='X':
                print "user-2 wins :) "
                break
        if tttboard[0]==tttboard[3] and tttboard[3]==tttboard[6]:
            if tttboard[6]=='O':
                print "user-1 wins :) "
                break
            elif tttboard[6]=='X':
                print "user-2 wins :) "
                break
        if tttboard[1]==tttboard[4] and tttboard[4]==tttboard[7]:
            if tttboard[7]=='O':
                print "user-1 wins :) "
                break
            elif tttboard[7]=='X':
                print "user-2 wins :) "
                break
        if tttboard[2]==tttboard[5] and tttboard[5]==tttboard[8]:
            if tttboard[8]=='O':
                print "user-1 wins :) "
                break
            elif tttboard[8]=='X':
                print "user-2 wins :) "
                break
        if tttboard[0]==tttboard[4] and tttboard[4]==tttboard[8]:
            if tttboard[4]=='O':
                print "user-1 wins :) "
                break
            elif tttboard[4]=='X':
                print "user-2 wins :) "
                break
        if tttboard[2]==tttboard[4] and tttboard[4]==tttboard[6]:
            if tttboard[4]=='O':
                print "user-1 wins :) "
                break
            elif tttboard[4]=='X':
                print "user-2 wins :) "
                break

        ch=raw_input('do you want to continue y or n')
        if (ch=='y')
            continue
        else
            break



