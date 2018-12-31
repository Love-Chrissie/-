#!/usr/bin/env python3  
# encoding: utf-8  

""" 
@version: v1.0 
@author: 四月是你的谎言
@contact: 389641222@qq.com 
@site:  
@software: PyCharm 
@file: ConjugateGradient
@time: 2018/10/11 9:31 AM 
"""
import time
import numpy as np


def ConjugateGradient(A, B):
    error = 1e-8
    n = len(B)
    x = np.mat(np.zeros(n)).T
    r0 = B-A*x
    p = r0
    k = 0
    while(k <= n):
        alpha = r0.T*r0/(p.T*A*p)
        x = x+alpha[0, 0]*p
        r = r0-alpha[0, 0]*A*p
        if np.linalg.norm(r) < error:
            break
        else:
            beta = r.T*r/(r0.T*r0)
            p = r+beta[0, 0]*p
            k = k+1
            r0 = r
    return x


def main():
    A = np.mat([[0.78, -0.02, -0.12, -0.14],
                [-0.02, 0.86, -0.04, 0.06],
                [-0.12, -0.04, 0.72, -0.08],
                [-0.14, 0.06, -0.08, 0.74]])
    B = np.mat([0.76, 0.08, 1.12, 0.68]).T
    start = time.process_time()
    X = ConjugateGradient(A, B)
    end = time.process_time()
    print("Conjugate Gradient Method for the solution:")
    for x in X:
        print("{:10.6f}".format(x[0, 0]))
    print("The program use %f ms" % ((end - start)*1000))


if __name__ == "__main__":
    main()
