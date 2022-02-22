import os
import numpy as np
from matplotlib import pyplot as plt
import subprocess

import pandas as pd

df = pd.DataFrame()
# .run as run
file = open("input.txt", 'w')
print(100, 100, 50, 50, 1000, file=file)
file.close()

input = open("input.txt", 'r')
output = open("output.txt", 'w')

# subprocess.run("./oneLauncher << input.txt > templ.txt")
# subprocess.run(["./oneLauncher"], input="10 10 5 5")
# subprocess.run(["make", "-f ../onemake"])
os.chdir("..")
os.system("ls")
os.chdir("oneParticle")
subprocess.run(["./oneLauncher"], stdin=input, stdout=output)

data = np.loadtxt("output.txt")
df['100']=data
print(df.head())
# plt.hist(data, bins=50)
# plt.show()