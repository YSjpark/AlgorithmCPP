#include <stdio.h>

int findGCD(int a, int b) {
  int gcd=1;
  int iend;
  iend = a > b ? b : a;
  // printf("%d\n", iend);
  
  bool valid = true;
  while(a > 1 && b > 1 && valid) {
    for(register int i=2; i<=iend; i++) {
      if(i == iend)
        valid = false;
      // printf("%d ",i);
      if (a%i != 0 || b%i != 0)
        continue;
      else if(a%i==0 && b%i==0) {
        gcd *= i;
        a = a/i;
        b = b/i;
      }
      
    }
    // printf("%d %d\n", a, b);
  }
  return gcd;
}

int findLCM(int gcd, int a, int b) {
  return (a/gcd) * (b/gcd) * gcd;
}

int main007() {
  int a, b;
  int gcd, lcm;
  scanf("%d %d", &a, &b);
  gcd = findGCD(a,b);
  lcm = findLCM(gcd, a, b);
  
  printf("%d\n", gcd);
  printf("%d\n", lcm);
  
  return 0;
}