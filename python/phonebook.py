myphonebook={'akash':9974779,'varun':648634683,'ritesh':6574512}

mob=raw_input('enter name')

if mob in myphonebook:
    print"name %s - phone no %d "%(mob,myphonebook[mob])
else:
    print"sorry name not found in phonebook"
