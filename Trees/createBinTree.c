#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *lchild;
    struct Node *rchild;
    int data;
}*root=NULL;

struct Q {
    int size;
    int f, r;
    struct Node **q;
};

void create(struct Q *q, int size){
    q->size = size;
    q->f=q->r=0;
    q->q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void circEnqueue(struct Q *q,struct Node * x){
    if((q->r+1) % q->size == q->f)
        return;
    q->r = (q->r+1) % q->size;
    q->q[q->r] = x;
}

struct Node * circDequeue(struct Q *q){
    if(q->f == q->r)
        return NULL;
    q->f = (q->f + 1) % q->size;
    return q->q[q->f];
}   

void createTree(){
    struct Node *p, *t;
    int x;
    struct Q q;
    create(&q, 100);
    printf("Enter root\n");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild=root->rchild=NULL;
    circEnqueue(&q, root);
    while (q.f!=q.r)
    {       
        p = circDequeue(&q);
        printf("Enter LC of %d\n", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            circEnqueue(&q, t);
        }
        printf("Enter RC of %d\n", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            circEnqueue(&q, t);
        }
    }
    
}


void preorder(struct Node *p){
    if(p){
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main(){
    createTree();
    preorder(root);
    printf("\n");
    return 0;
}