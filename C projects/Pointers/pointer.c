#include <stdio.h>
#include <stdlib.h>


void foo(int *w){
    *w = 10;
}



int main(int argc, char **argv){ //need 2 stars for 2 dimensional array, pointer to another pointer
    int str[20];
    printf("%p\n", str);
    printf("%p\n", str + 1);

    int *x;
    int y;
    y = 10; 
    x = &y; //ampersand returns memory location of variable
    *x = 8; //points to memory location of y and changes value of y to 8
            //*int reverts pointer back to actual value in memory

    foo(&y); //pass by value, copies value and passes it to function
              //pass by pointer is passing the pointer to the real variable, can change actual var in main
    printf("%d\n", y);

    return 0;
}