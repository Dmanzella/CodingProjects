#include <stdio.h>

int main(){

    FILE* fin;
    FILE* fout;
    fin = fopen("in.txt", "r");
    fout = fopen("out.txt", "rw");
    int x;

    while(!feof(fin)){
        fscanf(fin, "%d", &x);
        fprintf(fout, "%d\n", x);
    }
    
    fclose(fin);
    fclose(fout);
    return 0;

}