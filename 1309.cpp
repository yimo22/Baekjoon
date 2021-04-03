#include <iostream>
using namespace std;

#define MAX 1000000
#define DIV 9901
int dp[MAX+1][3];
// dp[n][pattern] : N by 2 size의 우리에서 pat으로 시작할때
//                   배치할 수 있는 경우의 수

// pat 0 : 위쪽 ,pat 1 : 아래 ,pat 2 : 아무것도 안채움.
int main(){
  int sizeof_N;
  cin >> sizeof_N;

  for(int i=0;i<3;i++) dp[1][i]=1;

  for(int i=2;i<=sizeof_N;i++){
    dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % DIV;
    dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % DIV;
    dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] )% DIV;
  }

  int result=0;
  for(int i=0;i<3;i++)
    result += dp[sizeof_N][i];
  
  cout << result % DIV << endl;


  return 0;
}