#include<stdio.h>

struct Array{
    int A[20];
    int size;
    int length;
};

int BinSearch(struct Array arr, int l, int h, int key){
    int mid;
    while(l<=h){
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key > arr.A[mid])
            l = mid+1;
        else
            h = mid-1;
    }
    return -1;
}

int RBinSearch(struct Array arr, int l, int h, int key){
    int mid;
    if( l <= h ){
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key > arr.A[mid])
            return RBinSearch(arr, mid + 1, h, key);
        else
            return RBinSearch(arr, l, mid - 1, key);
    }
    return -1;
}

int main(){
    int i;
    struct Array arr={{2,4,6,8,10}, 10, 5};
    printf("%d \n", BinSearch(arr, 0, arr.length, 6));
    printf("%d \n", RBinSearch(arr, 0, arr.length, 6));
    return 0;
}