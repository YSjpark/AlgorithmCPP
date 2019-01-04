#include <stdio.h>

int arr[1000][1000] = {0,};
int di[4] = {-1, 0, 1, 0};
int dj[4] = { 0, 1, 0,-1};
int main() {
  int W, H, N;
  scanf("%d %d", &W, &H);
  scanf("%d", &N);
  if (N > W*H) {
    printf("0");
    return 0;
  }
  
  int ni, nj, d, cnt;
  ni = H-1;
  nj = 0;
  d = 0; cnt=1;
  arr[ni][nj]=1;
  while(cnt!=N) {
    ni += di[d];
    nj += dj[d];
    if (ni<0 || nj<0 || ni>H-1 || nj>W-1 || arr[ni][nj]!=0) {
      ni -= di[d];
      nj -= dj[d];
      d = (d+1)%4;
      continue;
    }
    arr[ni][nj] = 1;
    cnt++;
  }
  printf("%d %d", nj+1, H-ni);
  
}