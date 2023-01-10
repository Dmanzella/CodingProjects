#include <stdio.h>

//can use break; to exit the loop as is.

int main(){


    int arr[10];

    printf("Please enter 10 numbers: ");

    int i = 0;
    while (i <= 9){
        scanf("%d",&arr[i]);
        i++;
    }
    
    
    i = 9;
    printf("Reversed numbers: ");
    while (i >= 0){
        printf("%d", arr[i]);
        i--;
    }


    printf("\n");

    return 0;
}