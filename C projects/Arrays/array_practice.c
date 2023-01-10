#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_rand(){
    int x;
    x = rand() % 10 + 1;
    printf("%d\n", x);
    return;
}

int sum_numbers(int x,int y){
    int sum;
    sum = x + y;
    return sum;
}


int main(){
    srand(time(NULL));
    
    print_rand();
    print_rand();
    print_rand();
    int x = 7;
    int y = 5;
    int sum = sum_numbers(x, y);
    printf("sum: %d\n", sum);

    return 0;
}