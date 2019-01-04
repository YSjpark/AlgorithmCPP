#include <stdio.h>
#include <math.h>

// N!에서 특정한 숫자 x가 몇개 들어갔는지 아는 방법.
// N/x의 몫 + N/x^2 의 몫 + N/x^3의 몫...을 더하면 된다.
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 2의 갯수 : 10개
// 4의 갯수 : 5개
// 8의 갯수 : 2개
// 16의 갯수 : 1개  -> 전체 2의 갯수 : 17개

int n,m;
int main() {
  scanf("%d %d", &n, &m);
  
  int n2=0, n5=0, tmp;
  for(int i=0; i<m; i++) {
    tmp = n-i;
    while(tmp % 2 == 0 || tmp % 5 == 0) {
      if (tmp%2 == 0) {
        n2 += 1;
        tmp /= 2;
      }
      if (tmp%5 == 0) {
        n5 += 1;
        tmp /= 5;
      }
    }
  }
  for(int i=1; i<=m; i++) {
    tmp = i;
    while(tmp % 2 == 0 || tmp % 5 == 0) {
      if (tmp%2 == 0) {
        n2 -= 1;
        tmp /= 2;
      }
      if (tmp%5 == 0) {
        n5 -= 1;
        tmp /= 5;
      }
    }
  }
  // printf("%d %d", n2, n5);
  printf("%d", n2>n5? n5: n2);

  return 0;
}