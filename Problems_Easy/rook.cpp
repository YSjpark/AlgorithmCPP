// BEST IDEA
// EXPORT

#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

int map[8][8];
int di[4] = {-1, 0, 1, 0}; // 상 좌 하 우
int dj[4] = { 0,-1, 0, 1};
int ki, kj;

vector<pair<int,int>> v;

int main009() {
  register int i,j;
  for(i=0; i<8; i++) {
    for(j=0; j<8; j++) {
      scanf(" %d", &map[i][j]);
      switch(map[i][j]) {
        case 1:
          ki = i;
          kj = j;
          break;
        case 2:
          v.push_back(pair<int,int>(i,j));
          break;
      }
    }
  }
  
  vector<pair<int,int>>::iterator it;
  bool canBeDie = false;
  int ni, nj, d;
  for(it=v.begin(); it!=v.end() && !canBeDie; it++) {
    pair<int,int> rook = *it;
    for(d=0; d<4 && !canBeDie; d++) {
      for(i=1; i<8; i++) {
        ni = rook.first + di[d]*i;
        nj = rook.second + dj[d]*i;
        if (ni<0 || nj<0 || ni>7 || nj>7 || map[ni][nj]==3)
          break;
        if (ni == ki && nj == kj) {
          canBeDie = true;
          // it = v.end();
          break;
        }
      }
    }
  }
  printf("%d", canBeDie);
  
  return 0;
}