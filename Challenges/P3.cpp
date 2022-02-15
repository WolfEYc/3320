#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

//helper function to get the sum of a segment of the numbers
int sum(int n, int* arr){  
  int s = 0;
  //printf("\t{");
  for(int i = 0; i < n; i++){
    //printf("%d, ", arr[i]);
    s += arr[i];
  }
  //printf("}\n");
  return s;
}

int minMaxSum(int n, int k, int* arr){
  if(k == 1){
    return sum(n, arr);
  }
  
  
  int tmp, tmp1, tmp2, min = -1, i, size, it, j;
  int *cpy = (int*) malloc(sizeof(int)*n);  
  
  for(j = 1; j < k; j++){
    for(i = 0; i < n; i++){
      for(size = 1; size <= n - i - 1; size++){
        if(size < j)
          continue;
        for(it = i; it < size + i; it++){
          cpy[it - i] = arr[it];
        }
        //printf("{");
        tmp1 = minMaxSum(size, j, cpy);

        
        for(it = 0; it < i; it++){
          
          cpy[it] = arr[it];
          //printf("%d, ", cpy[it]);
        }
        for(it = i + size; it < n; it++){
          
          cpy[it - size] = arr[it];
          //printf("%d, ", cpy[it]);
        }

        tmp2 = minMaxSum(n - size, k - j, cpy);
        //printf("}\n");
        
        tmp = std::max(tmp1, tmp2);
        //printf("%d\n", tmp);
        if(tmp < min || min == -1){
          min = tmp;
        }
      }
    }
  }    
  
  free(cpy);  
  return min;

}

int getMinMaxSum(int n, int k, int* arr){
  if(k > n || k < 1 || n < 1){
    return -1;
  }
  return minMaxSum(n, k, arr);
}


int main() 
{
  int n, k; 
  scanf("%d %d", &n, &k); 
  int *arr = (int*) malloc(sizeof(int)*n);
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  int min_max_cost = -1; 
  /* Do your stuff here; compute min_max_cost */

  min_max_cost = getMinMaxSum(n, k, arr);

  
  printf("%d\n", min_max_cost);
  free(arr);
  return 0; 
}
