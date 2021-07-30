#include <iostream>

using namespace std;
#define MAX 100000+1
int input[MAX];
int dp[MAX];
int main(){
  int N,answ = 0;
  cin >> N;
  for(int i=1;i<=N;i++){
    cin >> input[i];
  }

  // start
  // dp[N] = max(dp[N-1] + w[i] , w[i])
  answ = dp[1] = input[1];
  for(int i=2;i<=N;i++){
    dp[i] = max(dp[i-1]+input[i] ,input[i]);
    answ = max(answ,dp[i]);
  }
  cout << answ << endl;
}