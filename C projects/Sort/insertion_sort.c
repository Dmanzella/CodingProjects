#include <stdlib.h>


void insertion_sort(int* arr, int len){
    for(int i = 0; i < len; i++){
        for(int x = 0; x < i; x++){
            if(arr[i] < arr[x]){
                //insert arr[i] before arr[x]
                int tmp, tmp2;
                tmp = arr[x];
                arr[x] = arr[i];
                for(int y = x+1; y <= i; y++){
                    tmp2 = arr[y];
                    arr[y] = tmp;
                    tmp = tmp2;
                }
            }
        }
    }
}