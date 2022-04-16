#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
}*head;

typedef struct Node Node;

void create(int A[], int n){
    int i;
    Node *t, *last;
    head = (Node*)malloc(sizeof(Node));
    head->data = A[0];
    head->next=head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = (Node*)malloc(sizeof(Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(Node *p){
    do{
        printf("%d ",p->data);
        p = p->next;
    } while(p!=head);
    printf("\n");
}

void RecDisplay(Node *p){
    static int flag = 0;
    if(p!=head || !flag){
        flag = 1;
        printf("%d ", p->data);
        RecDisplay(p->next);
    }
    flag = 1;
}

int length(Node *p){
    int count=0;
    do{
        count++;
        p=p->next;
    }while(p!=head);
    return count;
}

void Insert(Node *p, int x, int pos){
    Node *t;
    int i;
    if(pos<0 || pos>length(p))
        return;
    if(pos==0){
        t = (Node*)malloc(sizeof(Node));
        t->data = x;
        if(!head){
            head = t;
            head->next=head;
        }
        else{
            while(p->next!=head)
                p=p->next;
            p->next = t;
            t->next=head;
            head = t;
        }
    } else {
        for(i=0;i<pos-1;i++)
            p=p->next;
        t = (Node*)malloc(sizeof(Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(Node *p, int pos){
    Node *q;
    int x, i;
    if(pos < 1 || pos > length(head))
        return -1;
    if(pos==1){
        while(p->next!=head)
            p=p->next;
        x = head->data;
        if(p==head){
            free(head);
            head=NULL;
        } else {
            p->next = head->next;
            free(head);
            head=p->next;
        }
    } else {
        for(i=0; i<pos-2; i++)
            p=p->next;
        q=p->next;
        p->next = q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main(){
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    Display(head);
    Insert(head, 6, 1);
    Display(head);
    printf("%d\n", Delete(head, 2));
    Display(head);
    return 0;
}