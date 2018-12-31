#!/usr/bin/env python3
# encoding: utf-8  

""" 
@version: v1.0 
@author: 四月是你的谎言
@contact: 389641222@qq.com 
@site:  
@software: PyCharm 
@file: thomas
@time: 2018/10/12 4:50 PM 
"""
import time
import numpy as np


def thomas(A, x):
    DIM = len(x)
    for i in range(DIM-1):
        R = A[0, i+1]/A[1, i]
        A[0, i+1] -= R*A[1, i]
        A[1, i+1] -= R*A[2, i]
        x[i+1] -= R*x[i]
    x[DIM-1] /= A[1, DIM-1]
    for i in range(DIM-2, -1, -1):
        x[i] = (x[i]-A[2, i]*x[i+1])/A[1, i]

def main():
    A = np.array([[0.0, 11.0, 8.0, 5.0, 2.0],
                  [13.0, 10.0, 7.0, 4.0, 1.0],
                  [12.0, 9.0, 6.0, 3.0, 0.0]])
    b = np.array([3.0, 0.0, -2.0, 6.0, 8.0])
    DIM = len(b)
    start = time.process_time()
    thomas(A, b)
    end = time.process_time()
    print("The program use %f ms" % ((end - start) * 1000))
    for i in range(DIM):
        print(" " *12* (i-1), end="")
        print(bool(i)*"{:12.6f}".format(A[0, i]), end='')
        print("{:12.6f}".format(A[1, i]), end='')
        print(bool(DIM-1-i) * "{:12.6f}".format(A[2, i]), end='')
        print(" "*12*(DIM-1-i-1), end='')
        print("  |{:12.6f}".format(b[i]))


if __name__ == "__main__":
    main()
