#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


     char str[400];
     char str2[400];
     char str3[400];
     char str4[400];

     scanf("%399s", str);
     scanf("%399s", str2);
     strcpy(str3, str);

     strcat(str, str2);
     printf("%s\n", str);
     strcpy(str4, str);
     printf("%s\n", str3);

    return 0;
}