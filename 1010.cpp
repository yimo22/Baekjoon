/*
    joon - #1010
    다리놓기
    Coded by yimo22
*/
#include <iostream>

using namespace std;
long long dp[31][31];
int main(){
    int rept;
    int N , M;
    cin >> rept ;

    for(int i=0;i<rept;i++){
       cin >> N >> M;
        for(int j=1;j<=M;j++){
            dp[j][j]=1;
            dp[j][0]=1;
            for(int k=0;k<j;k++){
                // C(n+1,r+1) = C(n,r)+C(n,r+1)
                dp[j+1][k+1]=dp[j][k]+dp[j][k+1];
            }
        }
       cout << dp[M][N] << endl;
    }
    return 0;
}
