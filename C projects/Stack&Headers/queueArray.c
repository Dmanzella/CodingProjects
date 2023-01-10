#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void enqueue(struct queue* q, int data){
    if(q->queue_len == q->max_len-1){
        q->max_len = q->max_len * 2;
        q->queue = realloc(q->queue, sizeof(int) * q->max_len);
    }

    q->queue_len++;
    q->queue[q->queue_len] = data;
}

void dequeue(struct queue* q){
    if(q->queue_len != -1){
        for(int i = 0; i < q->queue_len - 1; i++){
            q->queue[i] = q->queue[i+1];
            q->queue_len--;
        }
    }
}

int front(struct queue* q){
    if(q->queue_len == -1){
        return INT_MIN;
    }
    return q->queue[0];
}
