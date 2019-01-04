#include <stdio.h>

int getGCD(int a, int b) {
  int tmp, r, gcd = 1;
  if (b>a) {
    tmp = a;
    a = b;
    b = tmp;
  }
  
  while(true) {
    r = a%b;
    if (r==0) {
      gcd = b;
      break;
    }
    else {
      a = b;
      b = r;
    }
  }
  return gcd;
}

int getLCM(int a, int b) {
  return (a*b)/getGCD(a,b);
}

int main() {
  int a1,a2,b1,b2, c1,c2, cgcd;
  scanf(" %d %d", &a1, &a2);
  scanf(" %d %d", &b1, &b2);
  
  c1 = a1*b2 + a2*b1; // 분자
  c2 = a2*b2; // 분모
  cgcd = getGCD(c1,c2);
  
  printf("%d %d\n", c1/cgcd, c2/cgcd);
  
  // printf("%d\n", getGCD(20,30));
  // printf("%d\n", getLCM(20,30));
  
  

  return 0;
}