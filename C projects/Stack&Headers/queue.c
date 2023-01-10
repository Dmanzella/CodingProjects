#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue* enqueue(struct queue* q, int data){
    struct node* tmp = malloc(sizeof(struct node));
    tmp->data = data;
    if(q->front_queue == NULL){
        q->front_queue = tmp;
        q->back_queue = tmp;
        return q;
    }
    q->back_queue->next = tmp;
    q->back_queue = tmp;
    return q;
}

struct queue* dequeue(struct queue* q){
    if(q->front_queue == NULL){
        return NULL;
    }
    struct node* tmp = q->front_queue;
    q->front_queue = q->front_queue->next;
    free(tmp);
    return q;
}

int front(struct queue* q){
    if(q->front_queue == NULL){
        return INT_MIN;
    }
    return q->front_queue->data;
}
