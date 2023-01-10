#include <stdio.h>
#include <stdlib.h>

void foo(int *max, int* sum, int *product){
    *max = 10;
    *sum = 10;
    *product = 10;
}

int main(int argc, char **argv){
    
    int max;
    int sum;
    int product;
    foo(&max, &sum, &product);
    printf("%d %d %d\n", product, max, sum);
    return 0;
}