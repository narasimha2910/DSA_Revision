#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
     int length;
};

void Display(struct Array arr){
    int i;
    for(i=0;i<arr.length;i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

void Append(struct Array *arr, int x){
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
        // arr->length++;
}

void Insert(struct Array *arr, int index, int x){
    int i;
    if(index >=0 && index<=arr->length){
        for(i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i-1];
    arr->A[index] = x;
    arr->length++;
    }
}

int Delete(struct Array *arr, int index){
    int x=0,i;
    if(index>=0 && index<arr->length){
        x=arr->A[index];
        for(i=0; i<arr->length-1;i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
    return -1;
}

int main() {
    struct Array arr;
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    arr.length = n;
    printf("\nEnter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d", &arr.A[i]);
    Display(arr);
    Append(&arr, 10);
    Insert(&arr, 0, 11);
    Display(arr);
    printf("%d\n", Delete(&arr, 0));
    Display(arr);
    return 0;
}