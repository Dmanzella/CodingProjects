#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char email[20];
    char first[20];
    char last[20];
    float gpa;
    char classList[20][20];
};

int main(int argc, char *argv[]){

    FILE* f = NULL;
    f = fopen(argv[1], "r");
    struct student x;
    strcopy(x.first, fscanf("%s", x.first));
    printf("%s\n", x.first);

    char email[100] = {0};
    strcat(email, x.first);
    strcat(email, "x");
    strcat(email, x.last);
    strcat(email, "@email.com");
    strcopy(x.email, email);
    printf("%s\n", x.email);

    int prev_class_num = 0;
    char class_grade;
    for (int i = 0; i < prev_class_num; i++){
        fscanf("%s", &class_grade);
        fscanf("%d", &prev_class_num);
    }


    return 0;
}

