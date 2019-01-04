#include <stdio.h>

int main004() {
  int N, S, row[201];
  scanf(" %d %d", &N, &S);
  int num=S;
  for(int i=0; i<N; i++) {
    for(int j=N-i-1; j>0; j--)
      printf(" ");
    for(int j=0; j<2*i+1; j++) {
      row[j] = num;
      // printf("%d", num);
      num++;
      if(num==10)
        num=1;
    }
    if (i%2 == 0)
      for(int j=2*i; j>=0; j--)
        printf("%d", row[j]);
    else
      for(int j=0; j<2*i+1; j++)
        printf("%d", row[j]);
    printf("\n");
  }

  //Please Enter Your Code Here

  return 0;
}