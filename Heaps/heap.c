#include <stdio.h>
#include <stdlib.h>

void Insert(int H[], int n){
    int i=n, temp = H[i];
    while(i > 1 && temp > H[i/2]){
        H[i] = H[i/2];
        i/=2;
    }
    H[i] = temp;
}

int Delete(int A[], int n){
    int i,j,x, temp;
    x=A[1];
    i=1; j=i*2;
    A[1] = A[n];
    A[n] = x;
    while(j < n-1){
        if(A[j+1] > A[j])
            j = j+1;
        if(A[i] < A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i=j;
            j = i*2; 
        } else
        break;
    }
    return x;
}

int main(){
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    for(i=2; i<=7; i++)
        Insert(H, i);
    for(i=1; i<=7; i++)
        printf("%d ", H[i]);
    printf("\n");
    // printf("%d \n", Delete(H, 7));
    //  HEAP SORT
    for(i=7; i>1; i--)
        Delete(H, i);
    for(i=1; i<=7; i++)
        printf("%d ", H[i]);
    printf("\n");
    return 0;
}