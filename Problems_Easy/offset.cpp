#include <stdio.h>

int arr[5][5];

int di[]={-1, 0, 1, 0};
int dj[]={ 0, 1, 0,-1};
int main005() {
  for(register int i=0; i<5; i++)
    for(register int j=0; j<5; j++)
      scanf(" %d", &arr[i][j]);
  
  //for(register int d=0; d<4; d++)
  //  printf("%d %d\n", di[d], dj[d]);
  //Please Enter Your Code Here
  register int ni, nj;
  bool valid=true;
  for(register int i=0; i<5; i++) {
    for(register int j=0; j<5; j++) {
      valid = true;
      for(register int d=0; d<4; d++) {
        ni = i+di[d];
        nj = j+dj[d];
        if(ni<0 || nj<0 || ni>4 || nj>4)
          continue;
        if(arr[ni][nj] <= arr[i][j])
          valid = false;
      }
      if(valid)
        printf("* ");
      else
        printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}