#include <iostream>

using namespace std;

long long dp[10][100+1]; // dp[i][j] : 마지막 문자가 i일때 길이 j인 계단수의 갯수
int main(){
  int N;
  cin >> N;

  // 초기화
  dp[0][1] = 0;
  for(int i=1;i<10;i++){
      dp[i][1] = 1;
  }

  // dp[i][j] = dp[i-1][j-1] + dp[i+1][j-1] for 1<=i<=8
  // dp[i][j] = dp[i-1][j-1] for i = 9
  // dp[i][j] = dp[i+1][j-1] for i = 0
  for(int i=2;i<=N;i++){
    for(int j=0;j<10;j++){
      if(j==9)
        dp[j][i] = dp[j-1][i-1] % 1000000000;
      else if(j==0)
        dp[j][i] = dp[j+1][i-1]% 1000000000;
      else
        dp[j][i] = (dp[j-1][i-1] + dp[j+1][i-1])% 1000000000;
    }
  }

  long long answ = 0;
  for(int i=0;i<10;i++)
    answ = (answ + dp[i][N])%1000000000;

  cout << answ << endl;

  return 0;
}