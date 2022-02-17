# -*- coding: utf-8 -*-
"""

Generates a very large DUMMY results.txt

Created on Mon Apr 23 11:34:47 2018

@author: rarossi
"""

import scipy.stats as ss


def drange(start, stop, incr):
    ret = [start]
    while ret[-1] < stop:
        ret.append(ret[-1]+incr)
    return ret


vars_names = ['Crane Max Tension',
              'Crane Min Tension',
              'Pennant Max Tension',
              'Pennant Min Tension',
              'Sling1 Max Tension',
                'Sling2 Max Tension',
                'Sling3 Max Tension',
                'Sling4 Max Tension',
                'Sling5 Max Tension',
                'Sling6 Max Tension',
                'Sling7 Max Tension',
                'Sling8 Max Tension',
                'Sling9 Max Tension',]
#                'Sling10 Max Tension',
#                'Sling11 Max Tension',
#                'Sling1 Min Tension',
#                'Sling2 Min Tension',
#                'Sling3 Min Tension',
#                'Sling4 Min Tension',
#                'Sling5 Min Tension',
#                'Sling6 Min Tension',
#                'Sling7 Min Tension',
#                'Sling8 Min Tension',
#                'Sling9 Min Tension',
#                'Sling10 Min Tension',
#                'Sling11 Min Tension']

buffer = 'WaveHs\tWaveTp\tWaveDirection'
for v in vars_names:
    buffer += '\t%s' % v
buffer += '\n'

for hs in drange(1, 3.5, 0.1):
    print('\nHs: ', hs)
    for tp in drange(8, 18, 0.5):
        print(' ', tp, end='')
        for wd in (165, 180, 195):
            for seed in range(100):
                buffer += '%.1f\t%.2f\t%d' % (hs, tp, wd)
                for var in vars_names:
                    buffer += '\t%.3f' % ss.gumbel_r.rvs()
                buffer += '\n'

with open('results_dummy_insane.txt', 'w') as pf:
    pf.write(buffer)
