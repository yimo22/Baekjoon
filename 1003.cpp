/*
	joon - #1003
	피보나치 함수 - DP
	Coded by yimo22
*/
#include <iostream>
using namespace std;
#define INFI 9999
int dp_1[INFI];	// dp_1[N] == N에 대하여 fibo(1) 이 호출되는 횟수를 저장
int dp_0[INFI]; // dp_0[N] == N에 대하여 fibo(2) 가 호출되는 횟수를 저장
int main(){
	int input = 0;
	cin >> input;
	int rept = input;
	// 초기 set up
	dp_0[0] = 1;
	dp_0[1] = 0;
	dp_0[2] = 1;
	dp_1[0] = 0;
	dp_1[1] = 1;
	dp_1[2] = 1; 

	// res[i] == N(입력값)
	int res[input];
	for(int i=0;i<input;i++)
		cin >> res[i];

	for(int j=0;j<input;j++){
		// def. dp_#[N] == N일때 fibo(#)을 호출하는 횟수
		// 점화식.
		// dp_#[N] = dp_#[N-1]+dp_#[N-2]
		for(int i=3;i<=res[j];i++){
			dp_0[i] = dp_0[i-1]+dp_0[i-2];
			dp_1[i] = dp_1[i-1]+dp_1[i-2];
		}
		cout << dp_0[res[j]]<<" "<<dp_1[res[j]]<<"\n";
	}
}