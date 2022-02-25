import os
import numpy as np
from matplotlib import pyplot as plt
import subprocess
from tqdm import tqdm

import pandas as pd


os.chdir("..")
os.system("make -f onemake")
os.chdir("oneParticle")

# df = pd.DataFrame()
for hight_pow in tqdm(range(3, 8)):
    hight = int(2**(hight_pow))

    file = open("input.txt", 'w')
    print(hight, hight, hight//2, hight//2, 500, file=file)
    file.close()

    input = open("input.txt", 'r')
    output = open("output.txt", 'w')

    subprocess.run(["./oneLauncher"], stdin=input, stdout=output)

    data = np.loadtxt("output.txt")
    df = pd.read_csv('rub_results.csv', index_col=0)
    df[f'{hight}']=data
    df.to_csv('rub_results.csv')

print(df.head())

