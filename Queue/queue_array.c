#include<stdio.h>
#include<stdlib.h>

struct Q {
    int f, r, size;
    int *q;
};

void enqueue(struct Q *q, int x){
    if(q->r == q->size-1)
        return;
    q->r++;
    q->q[q->r] = x;
}

int dequeue(struct Q *q){
    if(q->f == q->r)
        return -1;
    q->f++;
    return q->q[q->f];
}

void display(struct Q q){
    int i;
    for(i=q.f+1; i<=q.r; i++)
        printf("%d ", q.q[i]);
    printf("\n");
}

void circEnqueue(struct Q *q, int x){
    if((q->r+1) % q->size == q->f)
        return;
    q->r = (q->r+1) % q->size;
    q->q[q->r] = x;
}

int circDequeue(struct Q *q){
    if(q->f == q->r)
        return -1;
    q->f = (q->f + 1) % q->size;
    return q->q[q->f];
}

void circDisplay(struct Q q){
    int i = q.f + 1;
    do{
        printf("%d ", q.q[i]);
        i = (i+1)%q.size;
    } while(i != (q.r + 1) % q.size);
    printf("\n");
}

int main(){
    // struct Q q;
    // scanf("%d", &q.size);
    // q.q = (int *)malloc(q.size * sizeof(int));
    // q.f = q.r = -1;
    // enqueue(&q, 10);
    // enqueue(&q, 20);
    // enqueue(&q, 30);
    // display(q);
    // dequeue(&q);
    // display(q);
    struct Q q;
    scanf("%d", &q.size);
    q.q = (int *)malloc(q.size * sizeof(int));
    q.f = q.r = 0;
    circEnqueue(&q, 10);
    circEnqueue(&q, 10);
    circEnqueue(&q, 10);
    circEnqueue(&q, 10);
    circDisplay(q);
    printf("%d\n",circDequeue(&q));
    circDequeue(&q);
    circDisplay(q);
    circDequeue(&q);
    circDisplay(q);
    circDequeue(&q);
    return 0;
}