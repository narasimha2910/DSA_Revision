#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void Reverse(struct Array *arr){
    int *B;
    B = (int*)malloc(arr->length*sizeof(int));
    int i,j;
    for(i=arr->length-1, j=0;i>=0;i--,j++)
        B[j] = arr->A[i];
    // printf("%d", B[0]);
    for(i=0;i<arr->length;i++)
        arr->A[i] = B[i];
}

void SwapReverse(struct Array *arr){
    int i,j,temp;
    for(i=0, j=arr->length-1;i<j;i++,j--){
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

void Display(struct Array arr){
    int i;
    for(i=0;i<arr.length;i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

int main(){
    struct Array arr={{2,4,6,8,10}, 10, 5};
    Reverse(&arr);
    Display(arr);
    SwapReverse(&arr);
    Display(arr);
    return 0;
}