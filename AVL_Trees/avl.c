#include<stdio.h>
#include<stdlib.h>

struct Node  {
    struct Node * rchild;
    int data;
    int height;
    struct Node *lchicld;
}*root=NULL;

typedef struct Node Node;

int Height(Node *p){
    int hl, hr;
    hl = p && p->lchicld?p->lchicld->height:0;
    hr = p && p->rchild?p->rchild->height:0;
    return hl > hr ? hl+1 : hr+1;
}

int bf (Node *p) {
    int hl,hr;
    hl = p && p->lchicld?p->lchicld->height:0;
    hr = p && p->rchild?p->rchild->height:0;
    return hl-hr;
}

Node * LLRotation(Node *p){
    Node *pl=p->lchicld, *plr=pl->rchild;
    pl->rchild = p;
    p->lchicld = plr;
    p->height = Height(p);
    pl->height = Height(pl);

    if(p==root)
        root = pl;
    return pl;
}

Node * LRRotation(Node *p){
    Node *pl=p->lchicld, *plr=pl->rchild;
    pl->rchild = plr->lchicld;
    p->lchicld = plr->rchild;
    plr->lchicld=pl;
    plr->rchild=p;

    pl->height = Height(pl);
    p->height = Height(p);
    plr->height = Height(plr);

    if(p==root)
        root = plr;
    return pl;
}

Node * Insert(Node *p, int key){
    Node *t=NULL;
    if(!p){
        t = (Node *)malloc(sizeof(Node));
        t->data=key;
        t->height=1;
        t->lchicld=t->rchild=NULL;
        return t;
    }
    if(key < p->data){
        p->lchicld = Insert(p->lchicld, key);
    }
    else if(key > p->data)
        p->rchild = Insert(p->rchild, key);
    p->height = Height(p);
    if(bf(p)==2 && bf(p->lchicld) == 1)
        return LLRotation(p);
    else if(bf(p)==2 && bf(p->lchicld) == -1)
        return LRRotation(p);
    // else if(bf(p)==-2 && bf(p->lchicld) == -1)
    //     return RRRotation(p);
    // else if(bf(p)==-2 && bf(p->lchicld) == 1)
    //     return RLRotation(p);
    return p;
}

void Inorder(Node *p){
    if(p){
        printf("%d ", p->data);
        Inorder(p->lchicld);
        Inorder(p->rchild);
    }
}



int main() {
    root = Insert(root, 50);
    Insert(root, 10);
    Insert(root, 20);
    Inorder(root);
    printf("\n");
    // Insert(root, 5);
    return 0;
}