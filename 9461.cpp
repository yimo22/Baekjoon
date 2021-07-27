#include <iostream>
#include <vector>
using namespace std;

vector<long long> answs;
long long dp[100+1];
int main(){

  int N,T;
  cin >> T;
  // 초기화
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 2;
    for(int j=6;j<=100;j++){
      dp[j] = dp[j-2] + dp[j-3];
    }
  for(int i=0;i<T;i++){
    cin >> N;
    answs.push_back(dp[N]);
  }

  for(int i=0;i<T;i++){
    cout << answs[i] << endl;
  }

  return 0;
}