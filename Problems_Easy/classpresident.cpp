// THINK DEEPER

#include <stdio.h>

int data[1000][5];
int voten[1000];
int students[5][10];
int main010() {
  int N;
  scanf(" %d", &N);
  for(register int ni=0; ni<N; ni++) {
    for(register int gi=0; gi<5; gi++) {
      scanf(" %d", &data[ni][gi]);
    }
  }
  
  bool vote=false;
  for(register int ni=0; ni<N; ni++) {
    for(register int nii=0; nii<N; nii++) {
      if (ni==nii)
        continue;
      vote = false;
      for(register int gi=0; gi<5; gi++) {
        if (data[ni][gi] == data[nii][gi]){
          vote = true;
          break;
        }
      }
      if (vote)
        voten[ni]++;
    }
  }
  
  int max=-987654321, maxidx=-1;
  for(register int ni=0; ni<N; ni++) {
    if (voten[ni] > max) {
      max = voten[ni];
      maxidx = ni;
    }
  }
  printf("%d", maxidx+1);

  return 0;
}