#include <iostream>
#include <stdlib.h>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    Rectangle r = {10,5};
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;

    Rectangle *p = &r;
    cout<<p->length<<endl<<(* p).length<<endl;

    Rectangle *q;
    q = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    // q = new Rectangle; (C++)
    q->length=15;
    q->breadth=7;
    printf("%d", q->length);
    free(q);
}