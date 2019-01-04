// BEST IDEA
// EXPORT

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int arr[9][9];
vector<pair<int, int>> v;

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}

int main008() {
  int i,j, max=-987654321;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      scanf(" %d", &arr[i][j]);
      if (max == arr[i][j]) {
        v.push_back(pair<int,int> (i,j));
      }
      else if (arr[i][j] > max) {
        max = arr[i][j];
        v.clear();
        v.push_back(pair<int,int> (i,j));
      }
    }
  }
  
  sort(v.begin(), v.end());
  vector<pair<int,int>>::iterator it;
  // for(it=v.begin(); it!=v.end(); it++) {
  //   printf("%d ", *it);
  // }
  
  // http://blog.naver.com/PostView.nhn?blogId=mdloopy&logNo=60123583226
  // 원소 순회하며 삭제하기
  pair<int, int> firstE = v.at(0);
  for(it=v.begin()+1; it!=v.end();) {
    if (it->first != firstE.first) {
      it = v.erase(it);
      continue;
    }
    it++;
  }
  
  sort(v.begin(), v.end(), sortbysec);
  
  // for(it=v.begin(); it!=v.end(); it++) {
  //   printf("(%d,%d)", it->first, it->second);
  // }
  
  printf("%d\n", max);
  printf("%d %d", v.at(0).first+1, v.at(0).second+1);
  
  
  //Please Enter Your Code Here
  
  // sort(arr[0], arr[0] + 9);
  // for(i=0; i<9; i++)
  //   printf("%d ", arr[0][i]);
  
  

  return 0;
}