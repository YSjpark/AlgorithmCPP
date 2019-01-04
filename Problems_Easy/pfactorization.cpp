#include <stdio.h>
#include <math.h>

// BEST PRACTICE?

#define MAX_NUM 10101 // sprt(10,000,000) + @

int primeCnt = 0;
int primes[MAX_NUM];

// Eratosthenes's screen
bool isPrime[MAX_NUM] = {false,};
void buildPrimeArr() {
  int m, mul;
  for(int i=2; i<MAX_NUM; i++){ 
    isPrime[i] = true; 
  }
  
  for(int i=2; i<MAX_NUM; i++) {
    if (!isPrime[i]) continue;
    
    m=2;
    mul = i*m; // 3*3 4*4 부터 지우면
    for(m=2; mul<=MAX_NUM; m++) {
      isPrime[mul] = false;
      mul = i*m;
    }
  }
  for(int i=2; i<MAX_NUM; i++) {
    if (isPrime[i]) {
      primes[primeCnt] = i;
      primeCnt++;
    }
  }
}


int main() {
  buildPrimeArr();
  //printf("%d \n\n", primes[primeCnt-1]);
  int num, val;
  scanf(" %d", &num);
  
  val = num;
  bool divided;
  while(true) {
    divided = false;
    for(int i=0; i<primeCnt; i++) {
      if (val % primes[i] == 0) {
        printf("%d\n", primes[i]);
        val /= primes[i];
        divided = true;
        break;
      }
    }
    if (!divided) {
      break;
    }
  }
  if (val != 1)
    printf("%d\n", val);

  return 0;
}