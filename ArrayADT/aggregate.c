#include<stdio.h>

struct Array{
    int A[20];
    int size;
    int length;
};

int get(struct Array arr, int index){
    if(index >=0 && index <arr.length)
        return arr.A[index];
    return -1;
}

void set(struct Array *arr, int index, int  value){
    if(index >=0 && index <arr->length)
        arr->A[index] = value;
}

int Max(struct Array arr){
    int i, max = arr.A[0];
    for(i=1;i<arr.length;i++)
        if(arr.A[i] > max)
            max = arr.A[i];

    return max;
}

int Min(struct Array arr){
    int i, min = arr.A[0];
    for(i=1;i<arr.length;i++)
        if(arr.A[i] < min)
            min = arr.A[i];

    return min;
}

int Sum(struct Array arr){
    int i, total = 0;
    for(i=0;i<arr.length;i++)
        total += arr.A[i];
    return total;
}

int Rsum(struct Array arr, int n){
    int total = 0;
    if(n<0)
        return 0;
    return Rsum(arr, n-1) + arr.A[n];
}

float Avg(struct Array arr){
    return (float)Sum(arr) / arr.length;
}

int main(){
    int i;
    struct Array arr={{2,4,6,8,10}, 10, 5};
    printf("%d\n", get(arr,0));
    set(&arr,0, 1);
    printf("%d\n", get(arr,0));
    printf("%d\n", Max(arr));
    printf("%d\n", Min(arr));
    printf("%d\n", Sum(arr));
    printf("%d\n", Rsum(arr, arr.length-1));
    printf("%f\n", Avg(arr));
    return 0;
}