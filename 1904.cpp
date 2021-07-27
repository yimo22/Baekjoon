#include <iostream>

using namespace std;

#define MAX 1000000
int dp[MAX];

int main(){
  int N;
  cin >> N;
  // initialize
  dp[0]=1;
  dp[1]=2;
  //start
  for(int i=2;i<N;i++){
    dp[i] = (dp[i-1]+dp[i-2])%15746;
  }

  cout << dp[N-1] << endl;

  return 0;
}