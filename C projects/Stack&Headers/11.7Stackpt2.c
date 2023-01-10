#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
//malloc and free are very recource extensive and slow to use large scale
//the faster an algorithm the more memory it takes, slower algorithms take up less memory
//use an array to create a more efficient stack funtionality of log_2(n) instead of n

struct stack{
    int max_len;
    int top_index;
    int* s;
};

struct stack* create_stack(){
    struct stack* st = malloc(sizeof(struct stack));
    st->s = malloc(sizeof(int));
    st->max_len = 1;
    st->top_index = -1;
    return st;
};

void push(struct stack* st, int data){
    //check if stack array is full, then make array double the size if full
    if(st->top_index == st->max_len-1){
        st->max_len = st->max_len * 2;
        st->s = realloc(st->s, sizeof(int) * st->max_len); //reallocates array to be double in size if full
    }

    st->top_index++;
    st->s[st->top_index] = data;
}

//not done with this function, all the others work
void pop(struct stack* st){
    if(st->top_index != -1){
        st->top_index--;
    }
}

int top(struct stack* st){
    if(st->top_index == -1){
        return INT_MIN;
    }
    return st->s[st->top_index];
}

int main(){

    struct stack* st = create_stack();
    printf("top of the stack %d with array size of %d\n", top(st), st->max_len);
    push(st, 1);
    printf("top of the stack %d with array size of %d\n", top(st), st->max_len);
    push(st, 2);
    printf("top of the stack %d with array size of %d\n", top(st), st->max_len);
    push(st, 3);
    printf("top of the stack %d with array size of %d\n", top(st), st->max_len);
    push(st, 4);



    return 0;
}