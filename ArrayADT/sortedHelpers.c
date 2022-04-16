#include<stdio.h>
#include<stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    for(i=0;i<arr.length;i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void InsertSort(struct Array *arr, int x){
    int i = arr->length-1;
    if(arr->length == arr->size)
        return;
    while(i >=0 && arr->A[i] > x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int IsSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++)
        if(arr.A[i] > arr.A[i+1])
            return 0;
    return 1;
}

void ShiftNegative(struct Array *arr){
    int i=0,j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0) i++;
        while(arr->A[j]>0) j--;
        if(i<j){
            swap(&arr->A[i], &arr->A[j]);
        }
    } 
}

int main(){
    struct Array arr={{2,4,6,8,10}, 10, 5};
    InsertSort(&arr, 3);
    Display(arr);
    printf("%d\n", IsSorted(arr));
    struct Array arr1={{-1,2,3,-5,2,-9}, 10, 6};
    ShiftNegative(&arr1);
    Display(arr1);
    return 0;
}