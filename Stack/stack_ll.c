#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*top=NULL;

void push(struct Node *p, int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(!t){
        printf("Stack Overflow\n");
        return;
    }
    t->data = x;
    t->next = top;
    top = t;
}

int pop(struct Node *p) {
    int x;
    if(!top){
        printf("Stack Underflow\n");
        return -1;
    }
    top = top->next;
    x = p->data;
    free(p);
    return x;
}

void Display(struct Node *p){
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int peek(struct Node *p, int pos){
    int i;
    for(i=0; p && i < pos-1; i++)
        p = p->next;
    return p ? p->data: -1;
}

int main () {
    push(top, 10);
    push(top, 20);
    push(top, 30);
    Display(top);
    printf("%d\n", pop(top));
    printf("%d\n", peek(top, 2));
    printf("%d\n", pop(top));
    Display(top);
    printf("%d\n", pop(top));
    printf("%d\n", pop(top));
    Display(top);
    return 0;
}