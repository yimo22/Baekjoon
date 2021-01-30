/*
*	joon - #11047
	동전0 - Greedy
	Coded by yimo22
*/
#include <iostream>
using namespace std;
int main(){
	int N,K;
	cin >> N >> K;
	if(N<0||N>10||K<0||K>100000000)
		return 0;
	
	
	// N가지의 동전종류를 통해서 총합 K 를 만드는 최소동전 수
	// 구하기
	int CoinType[N];
	for(int i=0; i<N;i++)
		cin>>CoinType[i];
	
	// Greedy 사용
	int k=0;
	int cnt = 0;
	while(true){
		if(K==0)
			break;
		
		// 최대 액수의 동전 종류 검사
		if(CoinType[k] > K || k == N){
			k--;
			// cnt 에 사용동전 수 추가
			cnt += K / CoinType[k];
			K = K % CoinType[k];
			
			// 잔액이 0이 될때 까지 반복
			k=0;
		}
		k++;
	}
	cout << cnt<<"\n";
}

