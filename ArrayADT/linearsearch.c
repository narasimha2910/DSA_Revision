#include<stdio.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array arr, int key){
    int i;
    for(i=0;i<arr.length;i++)
        if(key == arr.A[i])
            return i;
     return -1;
}

int Transposition(struct Array *arr, int key){
    int i;
    for(i=0;i<arr->length;i++)
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[i-1]);
            return i-1;
        }
     return -1;
}

int MoveToHead(struct Array *arr, int key){
    int i;
    for(i=0;i<arr->length;i++)
        if(key == arr->A[i]){
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
     return -1;
}

int main(){
    int i;
    struct Array arr={{2,4,6,8,10}, 10, 5};
    printf("%d\n", LinearSearch(arr, 10));
    printf("%d\n", Transposition(&arr, 10));
    printf("%d\n", MoveToHead(&arr, 10));
    for(i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
    return 0;
}