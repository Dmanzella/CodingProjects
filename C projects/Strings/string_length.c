#include <stdio.h>
#include <stdlib.h>
//should scan in a string and print out the length

int main(){
    char str[400];
    scanf("%399s", str);
    printf("%s\n", str);

    int num = 0;
    for (int a = 0; a < 400; a++){
        if (str[a] == 0){
            num = a;
            printf("string length is %d characters\n", num);
            return 0;
        }
    }

    return 0;
}