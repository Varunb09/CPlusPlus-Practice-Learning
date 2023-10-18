# it is used to represent 2D data in tabular format 
# data flow is mutable
import pandas as pd
import numpy as np

# using list
data = [[10,20,30,40,50],[5,10,15,20,25]]
column = ['1st','2nd','3rd','4th','5th']
df.DataFrame(data, index = ['A','B'], columns=column)
print df

# using dictionary
data2 = {'a':[65,10], 'b':[456,20], 'c':[23,30], 'd':[12,40]}
df2 = pd.DataFrame(data2,index = ['first','second'])
print df2

# # using dictionary
# data3 = {'first':{'a':100,'b':200,}, 'second':{'a':300,'b':400,}}
# df3 = pd.DataFrame(data3, index = ['first','second'])
# print df3

# using numpy
x = np.arange(5,30,5)
y = x*x+5
data4 = np.array([x,y], dtype = 'i2')
df4 = pd.DataFrame(arr, index = ['x','y'])
print df4
# print using indexing
print df4[1]
# display by column label
df4[3] = df4[1]+df4[2]
print df4

