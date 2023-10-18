mylist=[1,2,3,4,5,6,7,8,9,10,11]
n=len(mylist)
if (n%2!=0)


    c=(n/2)-1
    d=c+1
    print [mylist[c::-1]]+[mylist[n:d:-1]]
else

    c=(n/2)-1
    d=c
    print [mylist[c::-1]]+[mylist[n:d:-1]]