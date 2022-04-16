#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int a = 10;
    int *p;
    p=&a;

    cout<<a<<endl;
    cout<< *p <<endl;
    printf("%d", *p);

    int A[5] = {1,2,3,4,5};
    int *r;
    r=A; // r=&A[0];
    for (int i=0; i<5; i++){
        cout<<r[i]<<endl;
    }

    // Dynamic memory allocation

    int *q, *t;
    q = (int *)malloc(5 * sizeof(int));
    q[3] = 100;
    t = new int[5];
    t[4]=200;
    cout<<q[3]<< "  " << t[4]<<endl;

    free(q);
    delete [] t;

    return 0;
}