#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//not done
void decrypt(char* str){
    int length = strlen(str);
    for (int a = 0; a < length; a++){
             str[a] -= 'a';
             str[a] += 21;
             str[a] = str[a] % 26;
             str[a] += 'a';
    }
    printf("%s\n", str);
}

//changes every character in string 5 characters ahead, loops through alpahbet
int main(int argc, char* argv[]){

    int length = 0;

    for (int a = 1; a < argc; a++){
        int length = strlen(argv[a]);
        for (int b = 0; b < length; b++){
             argv[a][b] -= 'a';
             argv[a][b] += 5;
             argv[a][b] = argv[a][b] % 26;
             argv[a][b] += 'a';
        }
        printf("%s\n", argv[a]);
        decrypt(argv[a]);
    }
    return 0;
}


//subratc character by a to see where in alphabet it is