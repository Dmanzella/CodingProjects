#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char name_list[35][35], int str_count){
    char temp[16];
    for (int i = 1; i < str_count; i++){
        for (int b = 0; b < str_count; b++){
            if (strlen(name_list[b]) <= strlen(name_list[b + 1])){
            strcpy(temp, name_list[b]);
            strcpy(name_list[b], name_list[b+1]);
            strcpy(name_list[b+1], temp);
            }
        } 
    }
}

int main(int argc, char *argv[]){
    
    FILE *f;
    f = fopen(argv[1], "r");
    char name_list[35][35];
    
    //number of strings scanned
    int str_count;
    fscanf(f, "%d", &str_count);

    //reads in names, stores them in array
    printf("Names:\n");
    for (int i = 0; i < str_count; i++){
        fscanf(f, "%15s", name_list[i]);
        printf("     %s\n", name_list[i]);
    }
    
    sort(name_list, str_count);

    //print final sorted array
    printf("Sorted Strings:\n");
    for (int x = 0; x < str_count; x++){
        printf("     %s\n", name_list[x]);
    }

    printf("String Count: %d\n", str_count);
    fclose(f);
    return 0;
}