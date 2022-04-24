#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *lchild;
    struct Node *rchild;
    int data;
}*root=NULL;

void Insert(int key){
    struct Node *t=root, *r=NULL, *p;
    if(!root){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild=t->rchild=NULL;
        root = t;
        return;
    }
    while(t){
        r = t;
        if(key == t->data)
            return;
        else if(key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild=p->rchild=NULL;
    if(p->data < r->data) r->lchild=p;
    else r->rchild=p;
}

struct Node * rInsert(struct Node *p,int key){
    struct Node *t;
    if(!p){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = rInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = rInsert(p->rchild, key);
    return p;
}

void Inorder(struct Node *t){
    if(t){
        Inorder(t->lchild);
        printf("%d ", t->data);
        Inorder(t->rchild);
    }
}

struct Node * Search(struct Node *t, int key){
    while(t){
        if(key == t->data)
            return t;
        else if(key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}


int height(struct Node *p){
    int x, y;
    if(!p)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    return x>y?x+1:y+1;
}

struct Node *InPrec(struct Node *p){
    while(p && p->rchild)
        p = p->rchild;
    return p;
}

struct Node *InSucc(struct Node *p){
    while(p && p->lchild)
        p = p->lchild;
    return p;
}

struct Node * Delete(struct Node *p, int key){
    struct Node *q;
    if(!p)
        return NULL;
    if(!p->lchild && !p->rchild){
        if(p==root)
            root = NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else {
        if(height(p->lchild) > height(p->rchild)){
            q = InPrec(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}


int main() {
    struct Node *t;
    root = rInsert(root, 10);
    rInsert(root, 5);
    rInsert(root, 15);
    rInsert(root, 20);
    Inorder(root);
    printf("\n");
    printf("%d\n", Delete(root, 10)->data);
    Inorder(root);
    // t = Search(root, 11);
    // if(t){
    //     printf("%d ", t->data);
    // } else {
    //     printf("Not found");
    // }
    // printf("\n");
    return 0;
}