#include<stdio.h>
#include<stdlib.h>
#include<cstring>

using Board = char**;

void freeBoard(int n, Board board){
    for(int i = 0; i < n; i++){
        delete[] board[i];
    }
    delete[] board;
}

char** createBoard(int n){
    Board newBoard = new char*[n];
    for(int i = 0; i < n; i++){
        newBoard[i] = new char[n];
    }
    return newBoard;
}

char** getCopyBoard(int n, Board oldboard){
    char** newboard = createBoard(n);
    for(int i = 0; i < n; i++){
        memcpy(newboard[i], oldboard[i], n);    
    }
    return newboard;
}

void copyBoard(int n, Board board, Board copy){
    for(int i = 0; i < n; i++){
        memcpy(copy[i], board[i], n);    
    }
}

void scratchOff(int row, int col, int n, Board &board){
    for(int i = 0; i < n; i++){
        board[row][i] = '.';
        board[i][col] = '.';
    }
}

int countBoard(int n, int k, Board board){
    if(!k){
        return 1;
    }
    
    int i,j,count = 0;
    Board alt = nullptr;
    for(i = 0; i < n; i++){
        if(!memchr (board[i], '#', n))
            continue;
        
        for(j = 0; j < n; j++){
            if(board[i][j] == '#'){
                if(!alt)
                    alt = getCopyBoard(n, board);
                else
                    copyBoard(n, board, alt);

                scratchOff(i, j, n, alt);
                count += countBoard(n, k-1, alt);
                board[i][j] = '.';
                
            }
        }     
    }
    
    if(alt)
        freeBoard(n, alt);
    return count;  
}

int getCount(int n, int k, Board board){
    int count = countBoard(n, k, board);
    freeBoard(n, board);
    return count;
}


int main(int argc, char *argv[])
{
    int count=0;
    int n,k;
    int i,j;

    fscanf(stdin, "%d %d", &n, &k);
    Board board = createBoard(n);
    char tmp;
    fscanf(stdin, "%c", &tmp);
    count = 0;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            fscanf(stdin, "%c", &board[i][j]);
        }
        fscanf(stdin, "%c", &tmp);
    }


    /*
    Write your code here.
    The board is stored in the 2D array 'board'.
    The number of rows and columns of the board is stored in 'n'.
    The number of chess pieces is stored in 'k'.
    The result should be stored in 'count'.
    */

    count = getCount(n, k, board);


    printf("%d\n", count);

    

    return 0;
}
