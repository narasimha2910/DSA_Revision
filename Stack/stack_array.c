#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int top;
    int size;
    int *s;
};

struct cstack {
    int top;
    int size;
    char *s;
};

typedef struct cstack stack;

int isEmpty(stack st){
    return st.top==-1;
}

int isFull(stack st){
    return st.top == st.size - 1;
}

void push(stack *st, char x){
    if(isFull(*st))
        return;
    st->top ++;
    st->s[st->top] = x;
}

char pop(stack *st){
    int x = -1;
    if(isEmpty(*st)){
        printf("StackUnderflow\n");
        return "\0";
    }
    x = st->s[st->top];
    st->top--;
    return x;
}

int peek(stack st, int pos){
    if(st.top - pos + 1 < 0)
        return -1;
    return st.s[st.top - pos + 1];
}

int getTop(stack st){
    return st.top == -1 ? -1 : st.s[st.top];
}

int isBalanced(char *exp){
    int i;
    stack st;
    st.size = strlen(exp);
    st.s = (char *)malloc(st.size * sizeof(char));
    st.top = -1;
    for(i=0; exp[i] != '\0'; i++){
        if(exp[i] == '(')
            push(&st, exp[i]);
        else if(exp[i] == ')'){
            if(isEmpty(st)) return 0;
            pop(&st);
        }
    }
    return isEmpty(st) ? 1 : 0;
}

int main () {
    // stack st;
    // scanf("%d", &st.size);
    // st.s = (int *)malloc(sizeof(int) * st.size);
    // st.top = -1;
    // push(&st, 10);
    // printf("%d\n", getTop(st));
    // push(&st, 20);
    // printf("%d\n", getTop(st));
    // push(&st, 30);
    // printf("%d\n", getTop(st));
    // printf("%d\n", pop(&st));
    // printf("%d\n", peek(st, 2));
    // printf("%d\n", pop(&st));
    // printf("%d\n", pop(&st));
    // printf("%d\n", pop(&st));
    char *exp = "((a+b))\0";
    // scanf("%s", exp);
    // printf("%s", exp);
    printf("%d\n", isBalanced(exp));
    return 0;
}