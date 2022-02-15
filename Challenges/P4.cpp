#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;
//assuming that the matrix is in M[row][col] format

int minPathHelper(int row, int col, const int &max_row, const int &max_col, int** &arr, int** &dp){
    

    if(col == max_col){
        return 0;
    }

    int tmpr;
    int min = INT32_MAX;
    for(int r = row - 1; r <= row + 1; r++){
        if(r < 0){
            tmpr = max_row - 1;
        }else
        if(r >= max_row){
            tmpr = 0;
        }else{
            tmpr = r;
        }

        if(dp[tmpr][col] == INT32_MIN){
            dp[tmpr][col] = arr[tmpr][col] + minPathHelper(tmpr, col + 1, max_row, max_col, arr, dp);
        }

        if(dp[tmpr][col] < min){
            min = dp[tmpr][col];
        }
    }

    return min;


}

int minPath(int m, int n, int** &arr){

    int **dp = (int**) malloc(sizeof(int*)*m);
    int i, j;
    for(i = 0; i < m; i++){
        dp[i] = (int*) malloc(sizeof(int)*n);
        for(j = 0; j < n; j++){
            dp[i][j] = INT32_MIN;
        }
    }


    int min = INT32_MAX;
    int tmp;
    for(i = 0; i < m; i++){
        tmp = arr[i][0] + minPathHelper(i, 1, m, n, arr, dp);
        if(tmp < min){
            min = tmp;
        }
    }

    for(int i=0; i<m; i++) {
        free(dp[i]); 
    }
    free(dp);

    return min;

}

int main() 
{
    int m, n;
    auto discard = scanf("%d %d", &m, &n); 
    //printf("%d %d\n", m, n); 
    int **arr = (int**) malloc(sizeof(int*)*m);
    for(int i=0; i<m; i++) {
        arr[i] = (int*) malloc(sizeof(int)*n);
        for(int j=0; j<n; j++) {
            discard = scanf("%d", &arr[i][j]);
            //printf("%d ", arr[i][j]); 
        }
    //printf("\n");
    }

    int min_cost = minPath(m, n, arr); 
    /* Do your stuff here; compute min_max_cost */



    printf("%d\n", min_cost);
    for(int i=0; i<m; i++) {
        free(arr[i]); 
    }
    free(arr);
    return 0; 
}
