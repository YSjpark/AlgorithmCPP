#include <stdio.h>

int main000() {
  //XXXX 아래의 코드가 최선인가?
  
  //Please Enter Your Code Here
  int start_num, end_num;
  scanf("%d %d", &start_num, &end_num);
  
  register bool isPrime;
  for(register int num=start_num; num<=end_num; num++) {
    isPrime = true;
    for(register int d=2; d<num; d++) {
      if(num%d == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime && num>1)
      printf("%d ", num);
  }
  
  return 0;
}