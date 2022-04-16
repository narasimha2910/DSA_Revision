#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first=NULL, *second = NULL, *third = NULL;

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next=NULL;
    last=first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}

void create2(int A[], int n){
    int i;
    struct Node *t, *last;
    second = (struct Node*)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next=NULL;
    last=second;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}

void display(struct Node *ptr){
    while(ptr){
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void recursiveDisplay(struct Node *ptr) {
    if(ptr){
       printf("%d  ", ptr->data);
       recursiveDisplay(ptr->next);
    }
    
}

void recursiveReverseDisplay(struct Node *ptr) {
    if(ptr){
        recursiveReverseDisplay(ptr->next);
        printf("%d  ", ptr->data);
    }
    
}

int count(struct Node *p){
    int count = 0;
    while(p){
        count ++;
        p = p->next;
    }
    return count;
}

int Add(struct Node *p){
    int sum = 0;
    while(p){
        sum+=p->data;
        p = p->next;
    }
    return sum;
}

int rCount(struct Node *p){
    if(!p)
        return 0;
    else
        return rCount(p->next) + 1;
}

int rAdd(struct Node *p){
    if(!p)
        return 0;
    else
        return rAdd(p->next) + p->data;
}

int max(struct Node *p){
    int m = INT32_MIN;
    while (p)
    {
        if(p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int recMax(struct Node *p) {
    int m = 0;
    if(!p)
        return -32768;
    else {
        m = recMax(p->next);
        return m > p->data ? m : p->data;
    }
}

struct Node * search(struct Node *p, int key){
    while (p)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node * recSearch(struct Node *p, int key){
    if(!p)
        return NULL;
    if(key == p->data)
            return p;
    return recSearch(p->next, key);
}

struct Node * moveToHead(struct Node *p, int key){
    struct Node * q = NULL;
    while (p)
    {
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void insertNode(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if(index < 0 || index > count(p))
        return;
    
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(index == 0){
        t->next = first;
        first = t;
    }
    else {
        for(i=0; i< index-1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void sortedInsert(int key){
    struct Node *t, *p, *q;
    p=first;
    q=NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;

    if( !first ){
        first = t;
    } else {
        while(p && p->data < key){
            q = p;
            p = p->next;
        }
        if( p == first){        //If given value is smallest
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(int pos){
    struct Node *p, *q;
    int x=-1, i;
    if(pos < 1 || pos > count(first))
        return -1;
    if(pos==1){
        x = first->data;
        p = first;
        first = first->next;
        free(p);
    } else {
        p = first;
        q = NULL;
        for (i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        if(p){
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }
    return x;
}

int isSorted(struct Node *p){
    int x = INT32_MIN;
    while(p){
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void removeDuplicate(struct Node *p){
    struct Node *q = first->next;
    while(q){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        } else {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverseLL(struct Node *p){
    struct Node *q = NULL, *r = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void recRev(struct Node *q, struct Node *p){
    if(p){
        recRev(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void concatenate(struct Node *p, struct Node *q){
    third = p;
    while(p->next){
        p = p->next;
    }
    p->next = q;
    q = NULL;
}

void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data < q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }

    }
    if(p) last->next = p;
    if(q) last->next = q;
}

int isLoop(struct Node *f){
    struct Node *p=f, *q=f;
    do{
        p = p->next;
        q = q->next;
        q = q?q->next:NULL;
    }while(p && q && p!=q);
    return (p==q)?1:0;
}

// TODO: Write function for insert using last pointer
// TODO: Write function for reversing using array

int main() {
    int A[] = {1,2,3,4,6};
    create(A,5);
    struct Node *t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next=t1;
    // int B[] = {5, 10, 120};
    // create2(B,3);
    // display(first);
    // display(second);
    // concatenate(second, first);
    // Merge(first, second);
    // display(third);
    isLoop(first)?printf("\nLoop\n"):printf("\nNo Loop\n");
    // insertNode(second, 1, 11);
    // insertNode(second, 2, 12);
    // concatenate(first, second);
    // reverseLL(first);
    // display(first);
    // recRev(NULL, first);    
    // isSorted(first) ? printf("Sorted\n") : printf("Not Sorted\n");
    // removeDuplicate(first);
    // insertNode(first, 5, 0);
    // sortedInsert(10);
    // sortedInsert(0);
    // sortedInsert(8);
    // printf("%d\n", Delete(1));
    // display(first);
    // printf("%d\n", Delete(2));
    // recursiveDisplay(first);
    // printf("\n");
    // recursiveReverseDisplay(first);
    // printf("\n");
    // printf("%d\n", count(first));
    // printf("%d\n", rCount(first));
    // printf("%d\n", Add(first));
    // printf("%d\n", rAdd(first));
    // printf("%d\n", max(first));
    // printf("%d\n", recMax(first));
    // printf("%p\n", search(first, 3));
    // printf("%p\n", recSearch(first, 3));
    // printf("%p\n", moveToHead(first, 3));
    // display(second);
    return 0;
}