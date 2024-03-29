#ifndef QUEUE
#define QUEUE
//include neccessary standard libraries
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue{
    int max_len;
    int* queue;
    int queue_len;
};

void enqueue(struct queue* q, int data);
void dequeue(struct queue* q);
int front(struct queue* q);

#endif

