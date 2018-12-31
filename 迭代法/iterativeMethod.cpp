#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;
typedef double T;
const size_t MAX=1000;
const size_t N=4;
void SOR(const vector<vector<T> >& A, const vector<T>& B, vector<T>& X, const T w);
void G_S(const vector<vector<T> >& A, const vector<T>& B, vector<T>& X);
void Jacobi(const vector<vector<T> >& A, const vector<T>& B, vector<T>& X);
T Error(const vector<T>& X0, const vector<T>& X);
int main(){
    vector<vector<T> > A = {{0.78, -0.02, -0.12, -0.14},
                    {-0.02, 0.86, -0.04, 0.06},
                    {-0.12, -0.04, 0.72, -0.08},
                    {-0.14, 0.06, -0.08, 0.74}};
    vector<T> B = {0.76, 0.08, 1.12, 0.68};
    vector<T> X = {1.0, 1.0, 1.0, 1.0};
    SOR(A,B,X,1.1);
    // G_S(A,B,X);
    // Jacobi(A,B,X);
    for (int i=0; i<N; i++){
        cout << X[i] << endl;
    }
}
void Jacobi(const vector<vector<T> >& A, const vector<T>& B, vector<T>& X){
    vector<T> X0;
    for (int n=0; n<MAX; n++){
        X0.assign(X.begin(), X.end());
        for (int i=0; i<N; i++){
            X[i] = B[i];
            for (int j=0; j<i; j++){
                X[i] = X[i] - A[i][j]*X0[j];
            }
            for (int j=i+1; j<N; j++){
                X[i] = X[i] - A[i][j]*X0[j];
            }
            X[i] = X[i]/A[i][i];
        }
        //void print(const vector<vector<T> >& A, const vector<T>& B, vector<T>& X);
        cout << "第" << n << "次迭代，误差为："
        << setiosflags(ios::scientific) << Error(X0, X)
        << endl;
    }
}
void G_S(const vector<vector<T> >& A, const vector<T>& B, vector<T>& X){
    vector<T> X0;
    for (int n=0; n<MAX; n++){
        X0.assign(X.begin(), X.end());
        for (int i=0; i<N; i++){
            X[i] = B[i];
            for (int j=0; j<i; j++){
                X[i] = X[i] - A[i][j]*X[j];
            }
            for (int j=i+1; j<N; j++){
                X[i] = X[i] - A[i][j]*X0[j];
            }
            X[i] = X[i]/A[i][i];
        }
        //void print(const vector<vector<T> >& A, const vector<T>& B, vector<T>& X);
        cout << "第" << n << "次迭代，误差为："
        << setiosflags(ios::scientific) << Error(X0, X)
        << endl;
    }
}
void SOR(const vector<vector<T> >& A, const vector<T>& B, vector<T>& X, const T w){
    vector<T> X0;
    for (int n=0; n<MAX; n++){
        X0.assign(X.begin(), X.end());
        for (int i=0; i<N; i++){
            X[i] = B[i];
            for (int j=0; j<i; j++){
                X[i] = X[i] - A[i][j]*X[j];
            }
            for (int j=i; j<N; j++){
                X[i] = X[i] - A[i][j]*X0[j];
            }
            X[i] = X0[i]+w*X[i]/A[i][i];
        }
        //void print(const vector<vector<T> >& A, const vector<T>& B, vector<T>& X);
        cout << "第" << n << "次迭代，误差为："
             << setiosflags(ios::scientific) << Error(X0, X)
             << endl;
    }
}

T Error(const vector<T>& X0, const vector<T>& X){
    T error = 0.0;
    for (int i=0; i<N; i++){
        error += (X[i]-X0[i])*(X[i]-X0[i]);
    }
    return sqrt(error);
}
/*
void print(const vector<vector<T> >& A, const vector<T>& B, vector<T>& X){
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << A[i][j] << "\t";
        }
        cout << X[i] << "\t" << B[i] << endl;
    }
}
*/
