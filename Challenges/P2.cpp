#include<stdio.h>
#include<stdlib.h>
#include <algorithm>


int getMaxIndex(int i, int n, int* A){
    for(int j = i + 1; j < n; j++){
        if(A[j] > A[i]){
            i = j;
        }
    }
    return i;
}

int getMax(int i, int n, int* A){
    return A[getMaxIndex(i + 1, n, A)] - A[i];
}

int getMax(int n, int* A){
    if(n < 2)
        return 0; 
  
    int minInd = 0, currval = std::max(getMax(minInd, n, A), 0), imax;
    for(int i = 1; i < n - 1; i++){
        if(A[i] > A[minInd])
            continue;
        
        imax = getMax(i, n, A);
        if(imax > currval){
            currval = imax;
            minInd = i;
        }
    }
    return currval;
}


int main(int argc, char* argv[])
{
    int n;
    int *arr;


    fscanf(stdin, "%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        fscanf(stdin, "%d", &arr[i]);
    }

    int output;

    /*
    Write your program here.
    The array is stored in 'arr'.
    The length of the array is stored in 'n'.
    Compute the max(arr[j]-arr[i]) and store the result in 'output'
    */

    output = getMax(n, arr);

    
    printf("%d\n", output);
    free(arr);
    return 0;
}
