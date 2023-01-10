#include <stdio.h>

int main(){

    FILE* f;
    f = fopen("in.txt", "rw"); //rw+ appends and saves previous runs of program
    int x;
    do{
        fscanf(f, "%d", &x);
        printf("%d\n", x);
    }while(!feof(f)); //while we are not at the end of the file
    //do while loop is same as while but does check after one one through

    fprintf(f, "HELLO\n");


    fclose(f); //need to close file at the end every time you open one

    return 0;


}