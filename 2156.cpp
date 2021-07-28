#include <iostream>

using namespace std;

#define MAX 10000+1
int dp[MAX]; // dp[i] : i번쨰 포도주를 마실 때, 최대값
int w[MAX];
int main(){
  int N;
  cin >> N;
  for(int i=1;i<=N;i++)
    cin >> w[i];
  // init
  dp[1] = w[1];
  dp[2] = dp[1]+w[2];

  // start
  // dp[N] = dp[N-2] + w[N] : N-1번째를 안마실 경우
  // dp[N] = dp[N-3] + w[N-1] + w[N] : N-1번째를 마실 경우

  for(int i=3;i<=N;i++){
    dp[i] = max(dp[i-2],dp[i-3]+w[i-1]) + w[i];
    // i번째 포도주를 마실경우와 안마실 경우중, 최대값을 택한다.
    dp[i] = max(dp[i],dp[i-1]);
  }
  
  cout << max(dp[N],dp[N-1]) << endl;

  return 0;
}