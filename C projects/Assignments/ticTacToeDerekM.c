#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void print_matrix(char arr[3][3]);
void insert_move(char board[3][3], char row, int col);
bool did_i_win(char arr[3][3]);
void opp_move(char board[3][3]);
bool did_i_tie(char board[3][3]);

int main(){
    char row;
    int col;
    char board[3][3];
    //creates 3x3 board and assigns blank values
    for(int a = 0; a < 3; a++){
        for(int b = 0; b < 3 ; b++){
            board[a][b] = '-';
        }
    }
    //runs the actual game
    while(true){
    scanf("%c", &row);
    scanf("%d", &col);
    printf("you picked row %c, and column %d\n\n", row, col);
    scanf("%*c"); //need after scan
    insert_move(board, row, col);
    }
}

void print_matrix(char board[3][3]){
    for (int a = 0;a < 3; a++){
        for(int b = 0; b < 3; b++){
            printf("%c ", board[a][b]);
        }
        printf("\n");
    }
    printf("\n-----------\n\n");
}

void opp_move(char board[3][3]){
    
    srand(time(NULL));
    while (did_i_win(board) == 1 && did_i_tie(board) == 1){
        int a = rand() % 3;
        int b = rand() % 3;

        if (board[a][b] == '-'){
            board[a][b] = 'X';
            did_i_win(board);
            break;
        } 
    }
    
}

//inserts players moves, then inserts random opponent move with opp_move function and prints
void insert_move(char board[3][3], char row, int col){

    //takes input and assigns O to correct box
    for(int a = 0; a < 3; a++){
        if (row == 'a' && (a == col-1)){
                board[0][a] = 'O';
        }
        else if (row == 'b' && (a == col-1)){
                board[1][a] = 'O';
        }
        else if (row == 'c' && (a == col-1)){
                board[2][a] = 'O';
        }
    }
    opp_move(board);
    print_matrix(board); 
}

//works as intended, not efficient, didnt know how to do with for loops
bool did_i_win(char board[3][3]){
    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    //same as above but now checks for 'X' moves winning
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'){
        printf("\nWe have a winner!\n\n");
        return 0;
    }
    else{
       return 1;
        }
}

bool did_i_tie(char board[3][3]){
    int count = 0;
    for (int c = 0; c < 3; c++){
        for (int d = 0; d < 3; d++){
            if(board[c][d] == '-'){
                count++;
            }
        }
    }
    if (count == 0 && did_i_win(board) == 1){
        printf("\nTie Game!\n\n");
        return 0;
    }
    return 1;
}
