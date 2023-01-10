#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//syntax to declare functions before main to look nice and put all functions under main
void print_total_sum(int arr[5][5]);
void print_max_value(int arr[5][5]);
void print_sum_of_rows(int arr[5][5]);
void print_min_value(int arr[5][5]);
void print_product_of_col(int arr[5][5]);
void print_matrix(int arr[5][5]);
void print_max_col(int arr[5][5]);

int main(){
    srand(time(NULL));
    int arr[5][5];
    int a, b;
    for (a = 0;a < 5; a++){
        for(b = 0; b < 5; b++){
            arr[a][b] = 0;
        }
    }

    print_matrix(arr);

    printf("\n-------------------------\n\n");

    for (a = 0;a < 5; a++){
        for(b = 0; b < 5; b++){
            arr[a][b] = rand() % 10 + 1;
        }
    }

    print_matrix(arr);
    printf("\n");
    print_total_sum(arr);
    print_sum_of_rows(arr);
    print_product_of_col(arr);
    print_max_value(arr);
    print_min_value(arr);
    print_max_col(arr);

    return 0;
}

void print_matrix(int arr[5][5]){
    int a, b;
    for (a = 0;a < 5; a++){
        for(b = 0; b < 5; b++){
            printf("%d", arr[a][b]);
        }
        printf("\n");
    }
}

void print_total_sum(int arr[5][5]){
    int sum = 0;

    for (int a = 0;a < 5; a++){
        for(int b = 0; b < 5; b++){
            sum += arr[a][b];
        }
    }

    printf("Sum of all elements in array: %d\n", sum);
}

void print_sum_of_rows(int arr[5][5]){
    int sum;
     for (int a = 0;a < 5; a++){
        sum = 0;
        for(int b = 0; b < 5; b++){
            sum += arr[a][b];
        }
        printf("Sum of row %d: %d\n", a, sum);
    }
}

void print_product_of_col(int arr[5][5]){
    int product = 1;
    
     for (int b = 0;b < 5; b++){
        int product = 1;
        for(int a = 0; a < 5; a++){
            product *= arr[a][b];
        }
        printf("product of col %d: %d\n", b, product);
    }
}

void print_max_value(int arr[5][5]){
    int max = 0;

    for (int a = 0;a < 5; a++){
        for(int b = 0; b < 5; b++){
            if (arr[a][b] >= max){
                max = arr[a][b];
            }
        }
    }
    printf("max value in the array: %d\n", max);
}

void print_min_value(int arr[5][5]){
    int min = 10;

    for (int a = 0;a < 5; a++){
        for(int b = 0; b < 5; b++){
            if (arr[a][b] <= min){
                min = arr[a][b];
            }
        }
    }
    printf("min value in the array: %d\n", min);
}

void print_max_col(int arr[5][5]){
    int max = 0;
    for (int b = 0;b < 5; b++){
        int max = 0;
        for(int a = 0; a < 5; a++){
            if (arr[a][b] >= max){
                max = arr[a][b];
            }
        }
        printf("max col %d: %d\n", b, max);
    }
}

//how to scan in tictacotoe input
//char a; //row letter
//int b; //column #
//scanf("%c", &a);
//scanf("%d", &b);
//scanf("%*c"); //need after scan