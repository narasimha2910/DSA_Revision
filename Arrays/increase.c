#include<stdio.h>
#include<stdlib.h>

int main() {
    int *p, *q;
    int i;

    p = (int *)malloc(5 * sizeof(int));
    for(i=0;i<5;i++)
        p[i] = i+1;

    q = (int *)malloc(10 * sizeof(int));

    for(i = 0 ; i<5; i++)
        q[i] = p[i];

    free(p);
    p=q;
    q=NULL;

    for(i=0;i<10;i++)
        printf("%d ", p[i]);
    
    return 0;
}