#include <stdio.h>
#include <stdlib.h>

//structures on the heap

struct Bar {
    int x, y, z;
};

struct Foo {
    int age;
    char name[50];

    struct Bar *bar;
};


int main(int argc, char *argv[]){

    //on the stack
    //struct Foo f;

    //int on the heap
    int *x = malloc(sizeof(int));
    *x = 123;

    struct Foo *f = malloc(sizeof(struct Foo));
    //need the parenthesis because of order of operations or you could do f->age, f is dereferenced and point to int age on the heap to change it
    f->age = 42;

    printf("%p\n", f); //mem location of struct f
    printf("%d\n", f->age); 
    free(f);
    free(x);



    ////
    //arrays on the heap
    ////

    int *y = malloc(sizeof(int) * 64); //array of 64 ints on the heap
    for(int i = 0; i < 64; i++){
        y[i] = i; //equivelant to *(y + i)
    }

    //bracket notation already does a dereference
    //array of 8 foo structures
    struct Foo *foos = malloc(sizeof(struct Foo) * 8);
    printf("%p\n", foos);
    //how to set the third foo's age to 44
    foos[2].age = 44; //dont need arrow because of the bracket dereference
    printf("%d\n", foos[2].age);

    free(y);
    free(foos);


    //nesting structures, adds an extra layer to structures.
    struct Foo *nest;


    //set the bar's x property to 123
    nest->bar.x = 123; //need an array because foo is a pointer, need dot for bar because its not a pointer

    foo->bar = malloc(sizeof(struct Bar)); //structure on a structure, nested structure needs its own malloc so it exists
    free(nest);

    return 0;
}