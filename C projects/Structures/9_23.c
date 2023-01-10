#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char firstname[30];
    char lastname[30];
    float gpa;
    char email[100];
    char classes[10][10];
    int num_classes;
};

void print_student(struct student x){
    printf("First Name: %s\n", x.firstname);
    printf("Last name: %s\n", x.lastname);
    printf("GPA: %f\n", x.gpa);
    printf("email is: %s\n", x.email);

    printf("Classes:\n");
    for (int i = 0; i < x.num_classes; i++){
        printf("     %s\n", x.classes[i]);
    }
}

float get_gpa(char grade){
    if (grade == 'A') return 4.0;
    if (grade == 'B') return 3.0;
    if (grade == 'C') return 2.0;
    if (grade == 'D') return 1.0;
    if (grade == 'F') return 0.0;
    //return as a last case scenario
    return 0.0;
}

int main(int argc, char *argv[]){
    FILE *in;
    in = fopen(argv[1], "r");

    struct student x;
    fscanf(in, "%s", x.firstname);
    fscanf(in, "%s", x.lastname);

    int num_classes;
    fscanf(in, "%d", &num_classes);
    for (int i = 0; i < num_classes; i++){
        fscanf(in, "%s", x.classes[i]);
    }
    x.numclasses = num_classes;
    //gpa calc
    float gpa_sum = 0.0;
    int prev_classes;
    fscanf(in, "%d", &prev_classes);
    for(int i = 0; i < prev_classes; i++){
        //needs to scan an entire line of text with space and letter
        //space in scanf reads in white space no matter how big
        char class_grade;
        //scanf %*s reads in the string but doesnt save it, skips past it
        fscanf(in, "%*s %c", &class_grade);
        gpa_sum += get_gpa(class_grade);
    }
    x.gpa = gpa_sum / prev_classes;

    //student email
    strcat(x.email, x.firstname);
    strcat(x.email, ".");
    strcat(x.email, x.lastname);
    strcat(x.email, "@email.com");


    //printing summary of student
    print_student(x);

    fclose(in);
    return 0;
}