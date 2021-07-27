#include <iostream>
#include <algorithm>

using namespace std;

int w[300+1];
int dp[2][300+1];
int main(){
  int N;
  cin >> N;

  for(int i=1;i<=N;i++){
    cin >> w[i];
  }

  // 초기화
  dp[0][0] = 0;
  dp[1][0] = 0;
  dp[0][1] = w[1];
  dp[1][1] = 0;

  for(int i=2;i<=N;i++){
    dp[1][i] = max(dp[0][i-2],dp[0][i-1]) + w[i];
    dp[0][i] = max(dp[0][i-2],dp[1][i-2]) + w[i];
  }
  
  cout <<  max(dp[0][N],dp[1][N]) << endl;
  return 0;
}
