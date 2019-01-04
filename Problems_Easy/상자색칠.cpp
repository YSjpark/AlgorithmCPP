#include <stdio.h>

// BEST IDEA

int N, color[1000], arr[6];
bool visited[1000], found;

int nearIdx[6][4] = {
  {1,2,3,4},
  {0,2,4,5},
  {0,1,3,5},
  {0,2,4,5},
  {0,1,3,5},
  {1,2,3,4}
};

bool validate() {
  for(register int i=0; i<6; i++) {
    for(register int j=0; j<4; j++) {
      if ((arr[i] == arr[nearIdx[i][j]])
      && (arr[nearIdx[i][j]] != 0))
        return false;
    }
  }
  return true;
}
void dfs(int anchor, int depth) {
  if (found)
    return;
  if (depth==6) {
    if (validate())
      found = true;
    // for(int i=0; i<6; i++)
    //   printf("%d ",arr[i]);
    // printf(", %d %d\n", validate(), found);
  }
  else {
    for(int i=0; i<N; i++) {
      if(visited[i])
        continue;
      visited[i] = true;
      arr[depth] = color[i];
      dfs(i+1, depth+1);
      arr[depth] = -1;
      visited[i] = false;
    }
  }
}

int main006() {
  scanf(" %d", &N);
  for(register int i=0; i<N; i++)
    scanf(" %d", &color[i]);
  
  found=false;
  dfs(0,0);
  printf("%s", found ? "YES" : "NO");
  //Please Enter Your Code Here

  return 0;
}