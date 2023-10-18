#panel
# it is 3D container of data
import pandas as pd
import numpy as np

df1 = pd.DataFrame([[35,75,56],[45,90,48]])
df2 = pd.DataFrame([[20,35],[75,90]])
df3 = pd.DataFrame([[35.2,75.5,56.6],[45.4,90.7,48.8]])

p = pd.Panel({'item1':df1,'item2':df2, 'item3':df3})
print p

# accessing by item index
print p['item1']

# accessing by major index
print p.major_xs(1)

# accessing by minor index
print p.minor_xs(0)

