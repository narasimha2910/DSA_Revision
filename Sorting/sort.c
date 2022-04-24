#include<stdio.h>
#include<stdlib.h>

int B[100];

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int A[], int n){
    int flag, i, j;
    for(i=0; i<n-1; i++){
        flag = 0;
        for(j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(!flag) break;
    }
}

void InsertionSort(int A[], int n){
    int i, j, x;
    for(i=1; i<n; i++){
        j = i-1;
        x = A[i];
        while (j>-1 && A[j]>x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void SelectionSort(int A[], int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i; j<n; j++){
            if(A[j]<A[k])
                k=j;
        }
        swap(&A[i], &A[k]);
    }
}

int Partition(int A[], int l, int h){
    int pivot=A[l];
    int i=l, j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j)
            swap(&A[i], &A[j]);
    }while(i<j);
    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h){
    int j;
    if(l<h){
        j = Partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j+1, h);
    }
}

void Merge(int A[], int l, int m, int h){
    int i=l,j=m+1,k=l;
    while (i<=m && j<=h)
    {
        if(A[i]<A[j])
            B[k++] = A[i++];
        else 
            B[k++] = A[j++];
    }
    for(;i<=m;i++)
        B[k++] = A[i];
    for(;j<=h;j++)
        B[k++] = A[j];
    for(i=l;i<=h;i++){
        A[i] = B[i];
    }
}

void IMergeSort(int A[], int n){
    int p, i, l, m, h;
    for(p=2; p<=n; p=p*2){
        for(i=0; i+p-1<n; i=i+ p){
            l=i;
            h=i+p-1;
            m=(l+h)/2;
            Merge(A,l,m,h);
        }
    }
    if(p/2<n)
        Merge(A,0,p/2-1,n);
}

void MergeSort(int A[], int l, int h){
    int m;
    if(l<h){
        m=(l+h)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,h);
        Merge(A,l,m,h);
    }
}

int findMax(int A[], int n){
    int i,max=INT32_MIN;
    for(i=0;i<n;i++)
        if(A[i]>max)
            max = A[i];
    return max;
}

void CountSort(int A[], int n){
    int max,i,j;
    int *C;
    max = findMax(A,n);
    C = (int *)malloc(sizeof(int)*(max+1));
    for(i=0; i<max+1; i++)
        C[i] = 0;
    for(i=0; i<n; i++)
        C[A[i]]++;
    i=0;j=0;
    while (i<max+1)
    {
        if(C[i]){
            A[j++] = i;
            C[i]--;
        } else {
            i++;
        }
    }
    
}

void ShellSort(int A[], int n){
    int gap,i,j,temp;
    for(gap=n/2;gap>0;gap/=2){
        for(i=gap; i<n; i++){
            temp=A[i];
            j=i-gap;
            while (j>=0 && A[j]>temp)
            {
                A[j+gap] = A[j];
                j=j-gap;
            }
            A[j+gap] = temp;
        }
    }
}

int main() {
    int A[] = {10, 37, 2, 34, 20, 5};
    int Q[] = {10, 37, 2, 34, 20, 5, INT32_MAX};
    int i;
    // BubbleSort(A, 6);
    // InsertionSort(A, 6);
    // SelectionSort(A, 6);
    // QuickSort(Q, 0, 6);
    // IMergeSort(A,6);
    // MergeSort(A,0,5);
    // CountSort(A, 6);
    ShellSort(A,6);
    for(i=0; i<6; i++)
        printf("%d ", A[i]);
    printf("\n"); 
    return 0;
}