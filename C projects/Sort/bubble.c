#include <stdio.h>
#include <stdlib.h>

void sort(int* list, int len){
    int tmp;
    int counter = 0;
    int num_swaps;

    for(int i = 0; i < len; i++){
        num_swaps = 0;
        for(int k = 0; k < len - 1 - i; k++){
            if(list[k] > list[k + 1]){
                num_swaps++;
                tmp = list[k+1];
                list[k + 1] = list[k];
                list[k] = tmp;
            }
            counter++;
        }
        if(num_swaps == 0){
            break;
        }
    }
    printf("counter is %d\n", counter);
}

void printlist(int* list, int len){
    printf("List: ");
    for (int i = 0; i < len; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main(){
    int arr[10] = {3, 5, 1, 8, 7, 9, 0, 7, 6, 4};
    printlist(arr, 10);

    sort(arr, 10);

    printlist(arr, 10);
    return 0;
}