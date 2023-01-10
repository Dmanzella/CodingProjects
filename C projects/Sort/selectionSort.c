#include <stdio.h>
#include <stdlib.h>

void selection_Sort(int* arr, int len){
    int smallest;
    int small_pos;
    for(int i = 0; i < len; i++){
        smallest = arr[i];
        smallest_pos = i;
        for(int x = i + 1; x < len; x++){
            if(arr[x] < smallest){
                smallest = arr[x];
                smallest_pos = x;
            }
        }
        int tmp = arr[i];
        arr[i] = smallest;
        arr[smallest_pos] = tmp;
    }
}