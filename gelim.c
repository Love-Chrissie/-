#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#ifndef EPSILON
#define EPSILON 0.000000001
#endif
/* 高斯消去法 */
// DIM为宏声明的线性方程组阶数 
// process取0不打印消去过程，取1打印过程
// A[DIM][DIM]为系数矩阵，xx[DIM]为方程组右端项
int getlim( int process, double A[DIM][DIM], double xx[DIM] ){
    int k,i,j;
    if( process == 1 )
        printf("The process of elimination\n");
    /* 消去步骤 */
    for (k=0; k<DIM; k++){
        if( fabs(A[k][k]) < EPSILON ) return 1; // 高斯消去法要求对角线元素不能为0，对计算机来说就是绝对值极小数
    
    for(i=k+1; i<DIM; i++){
        A[i][k] = A[i][k] / A[k][k];
        for(j=k+1; j<DIM; j++)
            A[i][j] = A[i][j] - A[i][k] * A[k][j];
        xx[i] = xx[i] - A[i][k] * xx[k];
    }
    if( process==1 ){
        for(i=0; i<DIM; i++){
            for(j=0; j<DIM; j++) printf("%10.6f", A[i][j]);
            printf("   | %10.6f\n", xx[i]);
        }
        printf("\n");
    }
    }
    /* 回代求解 */
    xx[DIM-1] = xx[DIM-1] / A[DIM-1][DIM-1];
    for(i=DIM-2; i>=0; i--){
        for(j=i+1; j<DIM; j++)
            xx[i] = xx[i] - A[i][j] * xx[j];
        xx[i] = xx[i] / A[i][i];
    }
    return 0;
}