import numpy as np

# 输入系数矩阵应以numpy中的array类型输入
# LU分解又称doolittle分解
def doolittle(a, n):
    # 主行
    l = np.eye(n)
    u = np.zeros((n, n))
    for i in range(n):
        for j in range(i + 1, n):
            # 乘子，用于消去第j行的i列
            a[j, i] = a[j, i] / a[i, i]
            # 对i+1...n-1列
            for k in range(i + 1, n):
                a[j, k] = a[j, k] - a[j, i] * a[i, k]  # 消元
    for i in range(n):
        for j in range(n):
            if (j < i):
                l[i, j] = a[i, j]  # 下三角矩阵
            else:
                u[i, j] = a[i, j]  # 上三角矩阵
    return a,l,u
if __name__ == "__main__":
    A = np.array([[12.0, -3.0, 3.0],
                  [-18.0, 3.0, 1.0],
                  [1.0, 1.0, 3.0]])
    _, L, U = doolittle(A, 3)
    print(L)
    print(U)