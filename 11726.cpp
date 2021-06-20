/*
	jooon - #11726
	2*n 타일링 - DP/Overflow
	Coded by yimo22
*/
#include <iostream>
using namespace std;
#define MAX 1000
int dp[MAX+1];
int dp_carry[MAX+1];
int main(){
	int input=0;
	cin >> input;

	// 입력값 검사
	if(input > 1000 || input < 0){
		cout<<"Input Error\n";
		return 0;
	}

	// 초기값 설정
	// dp[k] == 2*k 크기의 직사각형을 1*2, 2*1 타일로 채우는 방법의 수
	dp[1] = 1;
	dp[2] = 2;

	// 점화식 : dp[N] = dp[N-2] + dp[N-1]
	for(int i=3;i<=input;i++){
		dp[i] = (dp[i-1]+dp[i-2])%10007;
	}

	// 정답 출력
	cout << dp[input]<< "\n";

	return 0;
}