#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int arr[5][5]);
void multiply_array(int arr1[5][5], int arr2[5][5]);

void main(){

    int arr1[5][5];
    int arr2[5][5];
    srand(time(NULL));

    for (int a = 0; a < 5; a++){
        for (int b = 0; b < 5; b++){
            arr1[a][b] = rand() % 40 + 11;
            arr2[a][b] = rand() % 40 + 11;
        }
    }

    print_matrix(arr1);
    printf("\n");
    print_matrix(arr2);
    printf("\n");
    multiply_array(arr1, arr2);
    
    
}

void print_matrix(int arr[5][5]){
    int a, b;
    for (a = 0;a < 5; a++){
        for(b = 0; b < 5; b++){
            printf("%d ", arr[a][b]);
        }
        printf("\n");
    }
}

void multiply_array(int arr1[5][5], int arr2[5][5]){
    
    int sum[5][5];

    for (int r = 0;r < 5; r++){
        for(int m = 0; m < 5; m++){
            sum[r][m] = 0;
        }
    }

    for (int a = 0; a < 5; a++){
        for (int b = 0; b < 5; b++){
            for (int c = 0; c < 5; c++){
                sum[a][b] += arr1[a][c] * arr2[c][b];
            }
        }
    }

    for (int x = 0;x < 5; x++){
        for(int y = 0; y < 5; y++){
            printf("%d ", sum[x][y]);
        }
        printf("\n");
    }

}