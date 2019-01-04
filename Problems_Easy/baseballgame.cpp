#include <stdio.h>
int N;
int dict[100][3] = {0, };
int strike[100] = {0, };
int ball[100] = {0, };

bool checkAns(int i, int j, int k) {
  // if (i==j || j==k || k==i)
    // return false;
  int st, bl;
  for(int n=0; n<N; n++) {
    st = 0; bl = 0;
    if (i==dict[n][0]) st++;
    else if(i==dict[n][1]||i==dict[n][2]) bl++;
    
    if (j==dict[n][1]) st++;
    else if(j==dict[n][0]||j==dict[n][2]) bl++;
    
    if (k==dict[n][2]) st++;
    else if(k==dict[n][0]||k==dict[n][1]) bl++;
    
    // printf("n%d %d %d | %d %d\n", n, strike[n], ball[n], st, bl);
    if (st!=strike[n] || bl!=ball[n])
      return false;
  }
  return true;
}

int main() {
  // int N;
  scanf("%d", &N);
  
  int _strike, _ball, _ans;
  int first, second, third;
  for(int n=0; n<N; n++) {
    scanf("%d", &_ans);
    scanf("%d", &_strike);
    scanf("%d", &_ball);
    first = _ans/100;
    second = (_ans%100)/10;
    third = _ans%10;
    dict[n][0] = first;
    dict[n][1] = second;
    dict[n][2] = third;
    strike[n] = _strike;
    ball[n] = _ball;
    //printf("%d %d %d\n", first, second, third);
  }
  
  int cnt=0;
  for(int i=1; i<=9; i++) {
    for(int j=1; j<=9; j++) {
      for(int k=1; k<=9; k++) {
        if (i!=j && j!=k && k!=i)
          if (checkAns(i,j,k)) cnt++;
      }
    }
  }
  printf("%d", cnt);

  return 0;
}