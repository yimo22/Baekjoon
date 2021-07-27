#include <iostream>

using namespace std;
#define MAX 500
int dp[MAX];
int triangle[500][500];
int main(){
  int N;
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<=i;j++){
      cin >> triangle[i][j];
    }
  }
  // start
  // dp[i] = w[i] + max(dp[2i],dp[2i+1]);
  // or dp[i] = w[i] + max(dp[i],dp[i+1]);
  for(int i=N;i>0;i--){
    for(int j=0;j<i;j++){
      dp[j] = triangle[i-1][j] + max(dp[j],dp[j+1]);
    }
  }

  cout << dp[0] << endl;

  return 0;
} 