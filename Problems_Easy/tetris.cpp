#include <stdio.h>

int height, width; // [5,20]
int onesAtH[20] = {0,};
bool meetFirstOne[20] = {false, };
int lastestZeroAtW[20] = {0,};
int main() {
  scanf("%d %d", &width, &height);
  int blk;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      scanf("%d", &blk);
      if (blk == 0 && !meetFirstOne[j])
        lastestZeroAtW[j] = i;
      else if (blk == 1) {
        onesAtH[i] += 1;
        meetFirstOne[j] = true;
      }
    }
  }
  /* 중간 결과 테스트
  int i, j;
  for(j=0; j<width; j++)
    printf("%d ", lastestZeroAtW[j]);
  printf("\n");
  for(i=0; i<height; i++)
    printf("%d\n", onesAtH[i]);
  */
  
  int solJdx = 0, solScore = 0;
  int fillStartI = 0;
  int caseScore = 0;
  for(int j=0; j<width; j++) {
    caseScore = 0;
    if (lastestZeroAtW[j] < 3)
      continue;
    
    // fillStartI = lastestZeroAtW[j] >= 3? lastestZeroAtW[j]-3: 0;
    // printf("%d, %d\n", fillStartI, lastestZeroAtW[j]);
    
    fillStartI = lastestZeroAtW[j] - 3;
    for(int i=fillStartI; i<=lastestZeroAtW[j]; i++) {
      if (onesAtH[i]+1 == width) {
        caseScore++;
      }
    }
    // printf("%d, %d.\n",j, caseScore);
    if (caseScore > solScore) {
      solScore = caseScore;
      solJdx = j;
    }
  }
  if (solScore == 0)
    printf("%d %d", 0, 0);
  else
    printf("%d %d", solJdx+1, solScore);
}