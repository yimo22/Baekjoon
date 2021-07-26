#include <iostream>

using namespace std;

int dp[50+1][50+1][50+1];
int main(){
  // 초기화
  for(int i=0;i<50;i++){
    for(int j=0;j<50;j++){
      dp[0][i][j] = 1;
      dp[i][j][0] = 1;
      dp[i][0][j] = 1;
    }
  }
  for(int i=1;i<50;i++){
    for(int j=1;j<50;j++){
      for(int k=1;k<50;k++){
        if( i > 20 || j > 20 || k > 20 )
          dp[i][j][k] = 1;
        else if( i < j && j < k )
          dp[i][j][k] = dp[i][j][k-1]+dp[i][j-1][k-1]-dp[i][j-1][k];
        else
          dp[i][j][k] = dp[i-1][j][k]+dp[i-1][j-1][k]+dp[i-1][j][k-1]-dp[i-1][j-1][k-1];
      }
    }
  }

  while(1){
    int a,b,c;
    cin >> a >> b >> c;
    if( a== -1 && b == -1 && c == -1)
      break;
    printf("w(%d, %d, %d) = ",a,b,c);
    if( a <= 0 || b <=0 || c<=0)
      cout << 1 << "\n";
    else if( a>20 || b>20||c>20)
      cout << dp[20][20][20] << "\n";
    else
      cout << dp[a][b][c]<<"\n";
  }

  return 0;
}