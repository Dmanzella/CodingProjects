#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//
////data structures
//
//dynamic size list changing on user input, dont need scanf

struct node{
    int data;
    struct node *next; //points to next node
};

int length_ll(struct node* ll){
    struct node* walker = ll;
    int counter = 0;
    while(walker != NULL){
        counter++;
        walker = walker->next;
    }
    return counter;
}

void print_ll(struct node* ll){
    struct node* walker = ll;
    printf("Linked List Values: ");
    while(walker != NULL){
        printf("%d ", walker->data);
        walker = walker->next;
    }
    printf("\n");
}
 
 // 10/21  used to search nodes for a value or returns null
struct node* search_value(struct node* ll, int data){
    struct node* walker = ll;
    while(walker != NULL){
        if(walker->data == data){
            return walker;
        }
        walker = walker->next; //when it doesnt equal data, moves onto the next node
    }
    return walker;
};

struct node* delete_node(struct node* ll, struct node* del){
    if (ll == NULL){
        return NULL;
    }
    if(del == NULL){
        return ll;
    }

    struct node* walker_a = ll;
    struct node* walker_b = ll;
    if (ll == del){ //conditional check if delete node is first in list
        ll = ll->next;
        free(walker_a);
        return ll;
    }
    
    walker_a = walker_a->next;
    while(walker_a != NULL){
        if(walker_a == del){
            walker_b->next = walker_a->next;
            free(walker_a);
            return ll;
        }
        walker_a = walker_a->next;
        walker_b = walker_b->next;
    }
    return ll;
}

struct node* insert_node(struct node* ll, int data){
    if(ll == NULL){
        ll = malloc(sizeof(struct node)); 
        ll->data = data;
        ll->next = NULL;
        return ll; //makes node and returns local ll pointer to main, main_ll_pointer becomes local ll
    }
    
    struct node* walker = ll;
    while(walker->next != NULL){
        walker = walker->next;
    }   
    walker->next = malloc(sizeof(struct node));
    walker = walker->next;
    walker->data = data;
    walker->next = NULL;
    return ll;
};

//correct way to delete linked list
struct node* cleanup_ll(struct node* ll){
    struct node* walker = ll;
    while(ll != NULL){
        ll = ll->next;
        free(walker);
        walker = ll;
    }
    return NULL;
}

int main(int argc, char **argv){
    struct node *main_ll_pointer = NULL;

    main_ll_pointer = insert_node(main_ll_pointer, 8);
    main_ll_pointer = insert_node(main_ll_pointer, 9);
    main_ll_pointer = insert_node(main_ll_pointer, 10);
    main_ll_pointer = insert_node(main_ll_pointer, 15);
    main_ll_pointer = insert_node(main_ll_pointer, 2);
    
    print_ll(main_ll_pointer);
    printf("length of list: %d\n", length_ll(main_ll_pointer));


    struct node * n = search_value(main_ll_pointer, 10);
    if (n != NULL){
        printf("The value was found! %d\n", n->data);
    }
    else{
        printf("Value was not found\n");
    }

    print_ll(main_ll_pointer);
    main_ll_pointer = delete_node(main_ll_pointer, search_value(main_ll_pointer, 2)); //deletes node
    print_ll(main_ll_pointer);

    main_ll_pointer = cleanup_ll(main_ll_pointer);
    printf("Linked list is cleaned up\n");

    return 0;
}
