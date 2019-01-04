#include <stdio.h>

int N, arr[1000][1000]={0,};
int rowsum[1000] = {0,};
// 한줄만 먼저 계산
// (a1x 줄에서, a1만 알면 나머지는 다 빼서 알 수 있음)
int main() {
  scanf(" %d", &N);
  
  long sum=0;
  int rsum;
  for(int i=0; i<N; i++) {
    rsum = 0;
    for(int j=0; j<N; j++) {
      scanf(" %d", &arr[i][j]);
      sum += arr[i][j];
      rsum += arr[i][j];
    }
    rowsum[i] = rsum;
  }
  sum = sum/(2*(N-1));
  // printf("%d", sum);
  
  for(int i=0; i<N; i++) {
    printf("%d ", (rowsum[i]-sum)/(N-2));
  }

  return 0;
}