#include <stdio.h>
#include <iostream>

using namespace std;
int main001() {

  int num[9];
  register int i, j, cnt;
  for(i=0; i<9; i++) {
    cin >> num[i];
  }
  
  for(i=0; i<9; i++) {
    cnt = 0;
    for(j=0; j<9; j++) {
      if (i==j)
        continue;
      if (num[i] > num[j])
        cnt++;
      if (cnt>2)
        break;
    }
    if (cnt==1)
      break;
  }
  cout << num[i] << endl;
  cout << i+1 << endl;

  return 0;
}