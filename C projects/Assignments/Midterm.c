#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct products{
    char name[15][15];
    int calories[15];
};

struct store{
    char name[15];
    char address[30];
    struct products *prod;
};

int main(int argc, char *argv[]){
    FILE* f;
    f = fopen(argv[1], "r"); 
    int store_num;
    fscanf(f, "%d", &store_num);

    struct store *x = malloc(sizeof(struct store) * store_num); //creates array of store structures

    for (int i = 0; i < store_num; i++){
        int prod_num;
        fscanf(f, "%s", x[i].name);
        fscanf(f, "%s", x[i].address); 
        printf("%s\n", x[i].name);
        printf("%s\n", x[i].address);

        fscanf(f, "%d", &prod_num);
        x[i].prod = malloc(sizeof(struct products));
        for (int b = 0; b < prod_num; b++){
            fscanf(f, "%s", x[i].prod->name[b]);
            fscanf(f, "%d", &x[i].prod->calories[b]); 
            printf("%s\n", x[i].prod->name[b]);
            printf("%d\n", x[i].prod->calories[b]);
        }
        printf("\n");
    }
    //all scans are wroking as intended

    char user_prod[30];
    printf("what product are you looking for? ");
    scanf("%s", user_prod);

    for (int y = 0; y < store_num; y++){
        for (int z = 0; z < 25; z++){
            if (strcmp(user_prod, x[y].prod->name[z]) == 0){
                printf("%s sells %s!\n", x[y].name, x[y].prod->name[z]);
                z = 0;
                break;
            }
        }
    }

    free(x);
    fclose(f);
    return 0;
}