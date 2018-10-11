#define DIM 5
#include "gelim.c"
extern int gelim( int process, double A[DIM][DIM], double b[DIM]);
int main(int argc, char const *argv[])
{
    int i,j;
    static double A[DIM][DIM] = {
        {3.0, -2.0, 5.3, -2.1, 1.0},
        {1.0, 4.0, -6.0, 4.5, -6.0},
        {3.0, 6.0, -7.3, -9.0, 3.4},
        {-2.0, -3.0, 1.0, -4.0, 6.0},
        {1.0, -4.0, 6.5, 1.0, -3.0}
    };
    static double b[DIM] = {28.3, -36.2, 24.5, 16.2, 4.3};
    system("cls");
    if( gelim(1, A, b) == 1 ){
        printf(" The linear system hasn't solution!\n");
        printf(" Strike any key to exit!\n");
        getchar();
        exit(1);
    }
    printf("Gauss elimination method:\n");
    for(i=0; i<DIM; i++)
        printf("   %12.6f\n", b[i]);
    getchar();
    return 0;
}
