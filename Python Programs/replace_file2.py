import os
file = open('content.txt','a')
names=["ritesh","varun","narayan","anshul"]

# to write sequence
file.writelines(names)
file.close()
