#include <stdio.h>

void binNum(int num) {
  int tmp=num;
  char str[11]="0000000000";
  // printf("%s\n", str);
  int cnt=0;
  while(tmp > 0) {
    if (tmp%2 == 1)
      str[cnt] = '1';
    tmp /= 2;
    cnt++;
  }
  // printf("%s %d\n", str, cnt);
  if(cnt == 0)
    printf("0");
  for(register int i=cnt-1; i>=0; i--)
    printf("%c", str[i]);
}
int main003() {
  int num;
  scanf(" %d", &num);
  binNum(num);
  return 0;
}