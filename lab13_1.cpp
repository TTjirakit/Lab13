#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum = 0, sumsq = 0, product = 1, fracsum = 0 ;
    double max = A[0], min =A[0];

    for(int i=0 ; i<N ; i++){
        sum += A[i];
        sumsq += A[i]*A[i];
        product *= A[i];
        fracsum += 1.0/A[i];
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }

    B[0] = sum/N;
    double mean = B[0];
    B[1] = sqrt((sumsq/N)-(mean*mean));
    B[2] = pow(product,1.0/N);
    B[3] = N/fracsum;
    B[4] =  max;
    B[5] =  min;

}