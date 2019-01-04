#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  
  int num=0, cnt=0;
  if (n==1) {
    printf("1");
    return 0;
  }
  while(1) {
    cnt++;
    num += 6*cnt;
    if (num > n) {
      printf("%d", cnt+1);
      break;
    }
  }
  //Please Enter Your Code Here

  return 0;
}