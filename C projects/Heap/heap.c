#include <stdio.h>
#include <stdlib.h>

int main(){
    int x; 
    int y;
    int z[10];

    scanf("%d", &x);



    int *n;
    n = (int*)malloc(sizeof(int) * x); //calloc is the same as malloc but sets numbers to 0
    
    for (int i = 0; i < x; i++){
        n[i] = rand() % 10;
        printf("%d ", n[i]);
        printf("\n");
    }

    free(n); //frees memory, unfreed memory is bad, makes computer slow takes up resources





    return 0;
}