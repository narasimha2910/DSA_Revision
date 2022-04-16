#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    struct Node *next;
    int data;
}*first=NULL;

typedef struct Node Node;

void create(int A[], int n){
    Node *t, *last;
    int i;
    first = (Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev=first->next=NULL;
    last=first;
    for(i=1; i<n; i++){
        t=(Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next = t;
        last = t;
    }
}

void Display (Node *p){
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int length(Node *p){
    int count=0;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}

void Insert(Node *p, int x, int pos){
    Node *t;
    int i;
    if(pos<0 || pos >length(first))
        return;
    if(pos == 0){
        t=(Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next = first;
        t->prev = NULL;
        first->prev = t;
        first = t;
    } else {
        t=(Node *)malloc(sizeof(struct Node));
        t->data=x;
        for(i=0; i<pos-1; i++)
            p=p->next;
        t->next = p->next;
        t->prev = p;
        if(p->next) p->next->prev = t;
        p->next = t;
    }
}

int Delete(Node *p, int pos){
    int i, x;
    if(pos<1 || pos >length(first))
        return -1;
    if(pos == 1){
        first = first->next;
        x = p->data;
        free(p);
        if(first) first->prev = NULL;
    } else {
        for(i=0; i<pos-1; i++)
            p = p->next;
            x = p->data;
            p->prev->next = p->next;
            if(p->next) p->next->prev=p->prev;
            free(p);
    }
    return x;
}

void Reverse(Node *p){
    Node *t;
    while(p){
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p=p->prev;
        if(p && !p->next) first = p;
    }
}

typedef struct Node Node;

int main(){
    int A[] = {1, 2, 3};
    create(A,3);
    Display(first);
    Insert(first, 100, 2);
    Display(first);
    printf("%d\n", Delete(first, 3));
    Reverse(first);
    Display(first);
    return 0;
}