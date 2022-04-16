#include <iostream>

using namespace std;

int main() {
    int A[5], B[5] = {1,2,3,4,5}, C[10] = {2,4,6}, D[5] = {0};
    int E[] = {1,2,3,4,5,6};

    for(int i=0;i<5;i++)
        printf("%u \n", &A[i]); //Printing addresses of array A
    return 0;
}