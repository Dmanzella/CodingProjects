#ifndef STACK
#define STACK

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//used to include 3 node funtions in the header so you dont have to replicate them
//one .h files includes many .c files
////
///////// have to give the compiler the specific files where the functions actually exist
////

struct node{
    int data;
    struct node* next;
};

//fuctions in "stack.c" file
struct node* Push(struct node* stack, int data);
int Top(struct node* stack);
struct node* Pop(struct node* stack);



#endif