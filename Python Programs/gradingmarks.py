marks=int(raw_input('enter marks'))

if marks>90:
    print"Student has got 'A' grade"
elif 80<marks<90:
    print"Student has got 'B+' grade"
elif 70<marks<80:
    print"Student has got 'B' grade"
elif 60<marks<70:
    print"Student has got 'B-' grade"
elif 50<marks<60:
    print"Student has got 'C' grade"
else :
    print"Student has got 'F' grade"