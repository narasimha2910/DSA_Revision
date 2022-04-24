#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node *lchild;
    struct Node *rchild;
    int data;
}*root=NULL;

struct Stack {
    int top;
    int size;
    struct Node **data;
};

struct LStack {
    int top;
    int size;
    long int *data;
};

void push(struct Stack *st, struct Node *data){
    if(st->top == st->size-1)
        return;
    st->top ++;
    st->data[st->top] = data;
}

void Lpush(struct LStack *st, long int data){
    if(st->top == st->size-1)
        return;
    st->top ++;
    st->data[st->top] = data;
}

struct Node * pop(struct Stack *st){
    struct Node *t;
    if(st->top == -1)
        return NULL;
    t = st->data[st->top];
    st->top--;
    return t;
}

long int Lpop(struct LStack *st){
    long int t;
    if(st->top == -1)
        return -1;
    t = st->data[st->top];
    st->top--;
    return t;
}

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

void iterativePreorder(struct Node *t){
    struct Stack st;
    st.size=100;
    st.top=-1;
    st.data = (struct Node **)malloc(st.size * sizeof(struct Node *));
    while(t || st.top!=-1){
        if(t){
            printf("%d ", t->data);
            push(&st, t);
            t = t->lchild;
        } else {
            t = pop(&st);
            t = t->rchild;
        }
    }
}

void iterativeInorder(struct Node *t){
    struct Stack st;
    st.size=100;
    st.top=-1;
    st.data = (struct Node **)malloc(st.size * sizeof(struct Node *));
    while(t || st.top!=-1){
        if(t){
            push(&st, t);
            t = t->lchild;
        } else {
            t = pop(&st);
            printf("%d ", t->data);
            t = t->rchild;
        }
    }
}

void iterativePostorder(struct Node *t){
    struct LStack st;
    long int temp;
    st.size=100;
    st.top=-1;
    st.data = (long int *)malloc(st.size * sizeof(long int));
    while(t || st.top!=-1){
        if(t){
            Lpush(&st, (long int)t);
            t = t->lchild;
        } else {
            temp = Lpop(&st);
            if(temp > 0){
                Lpush(&st, -temp);
                t = ((struct Node *)temp)->rchild;
            } else {
                printf("%d ", ((struct Node *)(-1 * temp))->data);
                t = NULL;
            }
        }
    }
}

void levelOrder(struct Node *t){
    struct Q q;
    create(&q, 100);
    printf("%d ", t->data);
    circEnqueue(&q, t);
    while(q.f!=q.r){
        t = circDequeue(&q);
        if(t->lchild){
            printf("%d ", t->lchild->data);
            circEnqueue(&q, t->lchild);
        } 
        if(t->rchild){
            printf("%d ", t->rchild->data);
            circEnqueue(&q, t->rchild);
        }
    }
}

// TODO: Count, Height and Deg(2) functions
int main(){
    createTree();
    preorder(root);
    printf("\n");
    iterativePreorder(root);
    printf("\n");
    iterativeInorder(root);
    printf("\n");
    iterativePostorder(root);
    printf("\n");
    levelOrder(root);
    printf("\n");
    return 0;
}