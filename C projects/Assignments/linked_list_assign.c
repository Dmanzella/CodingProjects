#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct school{
    char name[30];
    char students[500][30];
    int studentNum;
    struct school* next;
};

//length, needed for school sort function
int school_length(struct school* school){
    struct school* walker = school;
    int counter = 0;
    while(walker != NULL){
        counter++;
        walker = walker->next;
    }
    return counter;
}

//works as intended
//creates school structures
struct school* s_tag(char name[30], struct school* school){
    if(school == NULL){
        school = malloc(sizeof(struct school));
        strcpy(school->name, name);
        school->next = NULL;
        school->studentNum = 0;
        return school;
    }
    
    struct school* walker = school;
    while(walker->next != NULL){
        walker = walker->next;
    }
    walker->next = malloc(sizeof(struct school));
    walker = walker->next;
    walker->studentNum = 0;
    strcpy(walker->name, name);
    walker->next = NULL;
    return school;
}

//student sort, can implement radix if time
void stSort(struct school* school){
    char tmp[30];
    for(int i = 0; i < school->studentNum; i++){
        for(int j = i+1; j < school->studentNum; j++){
            if(strcmp(school->students[i], school->students[j]) > 0){
                strcpy(tmp, school->students[i]);
                strcpy(school->students[i], school->students[j]);
                strcpy(school->students[j], tmp);
            }
        }
    }
}


//copy school names into an array, then sort and print
void scSort(struct school* school){
    int count = school_length(school);
    char tmpArr[count][30];
    int counter = 0;
    while(school != NULL){
        strcpy(tmpArr[counter], school->name);
        counter++;
        school = school->next;
    }

    char tmp[30];
    for(int i = 0; i < counter; i++){
        for(int j = i+1; j < counter; j++){
            if(strcmp(tmpArr[i], tmpArr[j]) > 0){
                strcpy(tmp, tmpArr[i]);
                strcpy(tmpArr[i], tmpArr[j]);
                strcpy(tmpArr[j], tmp);
            }
        }
    }
    for(int i = 0; i < counter; i++){
        printf("%29s\n", tmpArr[i]);
    }
}

//works as intended
//adds a student to list of students in a given school
void c_tag(struct school* school, char scName[30], char stName[30]){
    struct school* walker = school;
    int num;
    while(walker != NULL){
        if(strcmp(walker->name, scName) == 0){ 
            num = walker->studentNum;  
            strcpy(walker->students[num], stName); 
            walker->studentNum = walker->studentNum + 1;
        }
        walker = walker->next;
    }
}


//print schools in alphabetical order using scSort func
void ps_tag(struct school* school){
    printf("School List:\n");
    scSort(school);
}

//print all students from a school, uses stSort for sorting functionality
void pc_tag(struct school* school, char scName[30]){
    struct school* walker = school;
    int num;
    while(walker != NULL){
        if(strcmp(walker->name, scName) == 0){
            stSort(walker);
            printf("student list of %s:\n", walker->name);
            num = walker->studentNum;
            for (int i = 0; i < num; i++){
                printf("    %s\n", walker->students[i]);
            }
        }
        walker = walker->next;
    }
    printf("\n");
}


//remove school structure from list
struct school* rs_tag(struct school* school, char scName[30]){
    if(school == NULL){
        return NULL;
    }

    struct school* walker_a = school;
    struct school* walker_b = school;
    if (strcmp(school->name, scName) == 0){ //check if first school in list is the delete school
        school = school->next;
        free(walker_a);
        return school;
    }

    walker_a = walker_a->next;
    while(walker_a != NULL){
        if (strcmp(walker_a->name, scName) == 0){
            walker_b->next = walker_a->next;
            free(walker_a);
            return school;
        }
        walker_a = walker_a->next;
        walker_b = walker_b->next;
    }
    return school;
}


//remove student name from every school they are in
void rc_tag(struct school* school, char stName[30]){

    struct school* walker = school;
    int num;
    int pos;
    while(walker != NULL){
        num = walker->studentNum;
        for(int i = 0; i < num; i++){
            if(strcmp(walker->students[i], stName) == 0){
                pos = i;
                for(int b = pos; b < num; b++){
                    strcpy(walker->students[b], walker->students[b+1]);
                }
                walker->studentNum = walker->studentNum-1;
            }
        }
        
        walker = walker->next;
    }
}


//deletes all schools and ends program
struct school* q_tag(struct school* school){
    struct school* walker = school;
    while(school != NULL){
        school = school->next;
        free(walker);
        walker = school;
    }
    printf("schools are cleared\n");
    return NULL;
}


int main(int argc, char* argv[]){
    //command line checks
    char s[3] = {'s',':'};
    char c[3] = {'c',':'};
    char ps[4] = {'p','s',':'};
    char pc[4] = {'p','c',':'};
    char rs[4] = {'r','s',':'};
    char rc[4] = {'r','c',':'};
    char q[3] = {'q',':'};

    //initialize school 
    struct school* school = NULL;
    
    //checks cmd args and sends to proper funtions all work as intended
    while(true){
        char cmd[4];
        scanf("%3s", cmd);

        if(strcmp(cmd, s) == 0){
            char scName[30];
            scanf("%29s", scName);
            school = s_tag(scName, school);
        }
        else if(strcmp(cmd, c) == 0){
            char scName[30];
            char stName[30];
            scanf("%29s %29s", scName, stName);
            c_tag(school, scName, stName);
        }
        else if(strcmp(cmd, ps) == 0){
            ps_tag(school);
        }
        else if(strcmp(cmd, pc) == 0){
            char scName[30];
            scanf("%29s", scName);
            pc_tag(school, scName);
        }
        else if(strcmp(cmd, rs) == 0){
            char scName[30];
            scanf("%29s", scName);
            school = rs_tag(school, scName);
        }
        else if(strcmp(cmd, rc) == 0){
            char stName[30];
            scanf("%29s", stName);
            rc_tag(school, stName);
        }
        else if(strcmp(cmd, q) == 0){
            school = q_tag(school);
            break;
        }
    }
    return 0;
}

