#include<stdio.h>
#include<stdlib.h>

int G[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

struct Node {
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(!t){
        printf("Queue Full");
        return;
    }
    t->data = x;
    t->next=NULL;
    if(!front){
        front=rear=t;
    } else {
        rear->next=t;
        rear=t;
    }
}

int dequeue(){
    struct Node *t;
    int x;
    if(!front){
        printf("Queue is Empty");
        return -1;
    }
    x = front->data;
    t=front;
    front=front->next;
    free(t);
    return x;
}

int isEmpty(){
    return front==NULL;
}

//     1
//    / \
//   2   3
//   \   /
//     4
//    / \
//   5   6

void BFS(int i, int n){
    int visited[7] = {0}, u, v;
    struct Node q;
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while(!isEmpty())
    {
        u = dequeue();
        for(v=1; v<=n; v++){
            // printf("%d", v);
            if(!visited[v] && G[u][v]){
                printf("%d ", v);
                enqueue(v);
                visited[v] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int i, int n){
    static int visited[7] = {0};
    int v;
    if(!visited[i]){
        printf("%d ", i);
        visited[i] = 1;
        for(v=1; v<=n; v++)
            if(G[i][v] && !visited[v])
                DFS(v,n);
    }
}

int main() {
    BFS(4, 6);
    DFS(4,6);
    printf("\n");
    return 0;
}