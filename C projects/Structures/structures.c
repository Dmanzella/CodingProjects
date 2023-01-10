#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

struct user{
    char username[20];
    int level;
};

int main(){
    struct user x;

    x.level = 5;
    //set level of user x to 5
    strcopy(x.username, "user1"); //strcopy is the only way to put strings into a variable
    //set username of user x to user1
    printf("%s\n %d", x.username, x.level);
    return 0;
}