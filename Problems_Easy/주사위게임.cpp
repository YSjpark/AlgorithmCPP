#include <stdio.h>
int N;
int arr[1000][7];
void scan() {
  scanf(" %d", &N);
  int a,b,c;
  for(register int i=0; i<N; i++) {
    scanf(" %d %d %d", &a, &b, &c);
    arr[i][a]++;
    arr[i][b]++;
    arr[i][c]++;
  }
}
int getMaxScore() {
  int max = -987654321;
  int score;
  for(register int i=0; i<N; i++) {
    score = 0;
    for(register int j=7; j>0; j--) {
      if (arr[i][j] == 3) {
        score = 10000 + j*1000;
        break;
      }
      else if(arr[i][j] == 2) {
        score = 1000 + j*100;
        break;
      }
      else if(arr[i][j] == 1) {
        if (score < j*100)
          score = j*100;
      }
    }
    //printf("%d\n", score);
    if (score > max)
      max = score;
  }
  return max;
}
int main002() {
  scan();
  printf("%d", getMaxScore());

  return 0;
}