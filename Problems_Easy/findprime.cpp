#include <stdio.h>
#include <math.h>

#define MAX_NUM 1001

// Eratosthenes's screen
bool isPrime[MAX_NUM] = {false,};
void buildPrimeArr() {
  for(int i=2; i<MAX_NUM; i++) isPrime[i] = true;
  for(int i=2; i<MAX_NUM; i++) {
    if (!isPrime[i]) continue;
    for(int j=i+1; j<MAX_NUM; j++) {
      if (j%i == 0) isPrime[j] = false;
    }
  }
  // for(int i=1; i<50; i++) {
  //   if (isPrime[i]) printf("%d ", i);
  // }
}

// Brute force
bool queryPrime(int num) {
  int lastDiv = (int) ceil(sqrt(num));
  if (num==1) return false;
  else if(num==2) return true;
  
  for(int d=2; d<=lastDiv; d+=2) {
    if (num%d == 0)
      return false;
    if (d==2) --d;
  }
  return true;
}

int main() {
  int N, num[100];
  buildPrimeArr();
  
  int data, cnt=0;
  scanf(" %d", &N);
  for (int n=0; n<N; n++) {
    scanf(" %d", &data);
    if (queryPrime(data))
    // if (isPrime[data])
      cnt++;
  }
  printf("%d\n", cnt);
  
  // printf("%f\n", ceil(sqrt(12.0f)));
  // printf("%d %d\n", isPrime[0], isPrime[1]);
  
  
  //Please Enter Your Code Here

  return 0;
}