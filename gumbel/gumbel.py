# -*- coding: utf-8 -*-
"""

Benchmark of gumbel.c

Created on Fri Apr 20 13:53:05 2018

@author: rarossi
"""

import pandas as pd
import scipy.stats as ss
import numpy as np


def quant(x, p):
    x.sort()
    qi = p * (len(x) - 1)
    i = int(qi)
    return (qi-i)*(x[i+1]-x[i]) + x[i]


data = pd.read_table("results.txt")

# gumbel cdf(p) = mean - f * std
p = 0.9
f = np.sqrt(6)/np.pi * (0.5772 + np.log(-np.log(p)))

# Max
var = data.columns[3]
# g90
df1 = (data.groupby(['WaveHs', 'WaveTp', 'WaveDirection'])[var].mean() -
       f * data.groupby(['WaveHs', 'WaveTp', 'WaveDirection'])[var].std()).max(
       level=[0, 1]).reset_index()
# p90
df1[var+' p90'] = data.groupby(['WaveHs', 'WaveTp', 'WaveDirection'])[var].quantile(p).max(
                  level=[0, 1]).reset_index()[var]

for var in data.columns[4:]:
    if 'max' in var.lower():
        df1[var] = (data.groupby(['WaveHs', 'WaveTp', 'WaveDirection'])[var].mean() -
                    f * data.groupby(['WaveHs', 'WaveTp', 'WaveDirection'])[var].std()).max(
                    level=[0, 1]).reset_index()[var]
        df1[var+' p90'] = data.groupby(['WaveHs', 'WaveTp', 'WaveDirection'])[var].quantile(p).max(
                    level=[0, 1]).reset_index()[var]
    else:
        df1[var] = (data.groupby(['WaveHs', 'WaveTp', 'WaveDirection'])[var].mean() +
            f * data.groupby(['WaveHs', 'WaveTp', 'WaveDirection'])[var].std()).min(
            level=[0, 1]).reset_index()[var]
        df1[var+' p90'] = data.groupby(['WaveHs', 'WaveTp', 'WaveDirection'])[var].quantile(1-p).min(
                  level=[0, 1]).reset_index()[var]

print(df1)

print('Percentual difference - python versus C implementation')

fromC = '''
3.0    6    61.129    61.085    35.141    35.194
3.0    7    60.874    60.864    33.766    33.620
3.0    8    61.710    61.378    33.109    33.566
3.0   10    61.561    61.474    33.839    34.221
3.0   11    60.271    60.017    34.764    35.178
3.0   12    59.129    59.245    35.679    36.429
3.0   14    56.677    56.819    38.783    38.937
3.5    7    63.371    63.361    30.457    30.450
3.5    8    66.440    65.644    29.309    29.678
3.5   10    64.508    64.578    31.045    31.591
3.5   11    62.867    62.660    31.967    32.151
3.5   12    61.642    61.602    33.248    34.093
3.5   14    58.576    58.822    36.982    37.155
'''.strip()
fromC = [_.split('   ') for _ in fromC.split('\n')]
fromC = [[float(x) for x in line] for line in fromC]

dfC = pd.DataFrame(columns=df1.columns, data=fromC)

print(100*(df1-dfC)/df1)

# ######################
'''
For debugging into one sample...
sample165 = list(data[(data.WaveHs == 3.5) & (data.WaveTp == 14) & (data.WaveDirection == 165)]['Link1 Max Tension'])
sample180 = list(data[(data.WaveHs == 3.5) & (data.WaveTp == 14) & (data.WaveDirection == 180)]['Link1 Max Tension'])
sample195 = list(data[(data.WaveHs == 3.5) & (data.WaveTp == 14) & (data.WaveDirection == 195)]['Link1 Max Tension'])
print(max(quant(sample165, p), quant(sample180, p), quant(sample195, p)))

sample165 = list(data[(data.WaveHs == 3.5) & (data.WaveTp == 14) & (data.WaveDirection == 165)]['Link1 Min Tension'])
sample180 = list(data[(data.WaveHs == 3.5) & (data.WaveTp == 14) & (data.WaveDirection == 180)]['Link1 Min Tension'])
sample195 = list(data[(data.WaveHs == 3.5) & (data.WaveTp == 14) & (data.WaveDirection == 195)]['Link1 Min Tension'])
print(min(quant(sample165, 1-p), quant(sample180, 1-p), quant(sample195, 1-p)))
'''
