#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumBribes function below.
def minimumBribes(q):
    n = len(q)
    count = 0
    for i in range(n-1, -1, -1) :
        if(q[i] - (i+1) > 2) :
            print("Too chaotic")
            return
        for j in range(max(0, q[i]-2), i) :
            if(q[j] > q[i]) :
                count += 1
    print(count)

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
