#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *f=NULL, *r=NULL;


void enqueue(int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(!t){
        printf("Overflow\n");
        return;
    }
    t->data = x;
    t->next=NULL;
    if(!f){
        f=r=t;
        return;
    }
    r->next = t;
    r=t;
}

int dequeue(){
    int x;
    struct Node *p;
    if(!f){
        printf("Underflow\n");
        return -1;
    }
    p = f;
    f = f->next;
    x = p->data;
    free(p);
    return x;  
}

void display(){
    struct Node *p = f;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    return 0;
}