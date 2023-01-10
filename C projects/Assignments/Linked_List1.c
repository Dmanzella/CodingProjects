#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct school{
    char name[30];
    char students[500][30];
    int studentNum;
    struct school* next;
};

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

char* stSort(char* names[5000]){

}

void scSort(struct school* school){
    
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

//print schools, need to add alphabetical order sort 
//NOT DONE
void ps_tag(struct school* school){
    struct school* walker = school;
    printf("School List:    \n");
    while(walker != NULL){
        printf("        %s\n", walker->name);
        walker = walker->next;
    }
    printf("\n");
}

//print all students from a school, need to add alphabeticall order
void pc_tag(struct school* school, char scName[30]){
    struct school* walker = school;
    int num;
    while(walker != NULL){
        if(strcmp(walker->name, scName) == 0){
            printf("student list of %s:\n", walker->name);
            num = walker->studentNum;
            for (int i = 0; i < num; i++){
                printf("        %s\n", walker->students[i]); //need to figure out how to store students
            }
        }
        walker = walker->next;
    }
    printf("\n");
}

//works as intended
//remove store structure from list
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

//working as intended
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

//works as intended
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


//need to redo, use scanf's to read input
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
    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i], s) == 0){
            school = s_tag(argv[i+1], school);
        }
        else if(strcmp(argv[i], c) == 0){
            c_tag(school, argv[i+1], argv[i+2]);
        }
        else if(strcmp(argv[i], ps) == 0){
            ps_tag(school);
        }
        else if(strcmp(argv[i], pc) == 0){
            pc_tag(school, argv[i+1]);
        }
        else if(strcmp(argv[i], rs) == 0){
            school = rs_tag(school, argv[i+1]); //might need to switch to void
        }
        else if(strcmp(argv[i], rc) == 0){
            rc_tag(school, argv[i+1]);
        }
        else if(strcmp(argv[i], q) == 0){
            school = q_tag(school);
            return 0;
        }
    }
    return 0;
}

