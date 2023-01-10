#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct node* Push(struct node* stack, int data){
    struct node* tmp = malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = stack; //connect the new node to the last nade
    return tmp;
}

int Top(struct node* stack){
    if (stack == NULL){
        return INT_MIN;
    }
    return stack->data;
}

struct node* Pop(struct node* stack){
    if(stack == NULL){
        return NULL;
    }
    struct node* tmp = stack->next;
    free(stack);
    return tmp;
}


int main(int argc, char** argv){
    struct node* stack_head = NULL;
    stack_head = Push(stack_head, 1);
    stack_head = Top(stack_head, 1);
    stack_head


    return 0;
}
