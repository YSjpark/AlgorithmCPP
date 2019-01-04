#include <stdio.h>

bool visited[30] = {false,};
int cnt=0;
int n, m;
// 점화식으로 (DP), 약분해서 단순화 (현재 방법)
void combi(int anchor, int depth) {
  if (depth == m) {
    cnt++;
  }
  for(int i=anchor; i<n; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    combi(i+1, depth+1);
    visited[i] = false;
  }
}

int main() {
  long long ans;
  scanf("%d %d", &n, &m);
  
  ans = 1;
  
  int anchor = 1;
  for(int i=0; i<m; i++) {
    ans *= (n-i);
    if (ans%anchor == 0) {
      ans /= anchor;
      anchor += 1;
      if (anchor > m)
        anchor = 987654321;
    }
  }
  if (anchor != 987654321) {
    while(true) {
      ans /= anchor;
      anchor+=1;
      if (anchor > m)
       break;
    }
  }
  printf("%d", ans);
    
    
  // for(int i=m; i>0; i--)
  //   ans /= i;
  // printf("%d", ans);
  
  // combi(0,0);
  // printf("%d", cnt);
  
  return 0;
}