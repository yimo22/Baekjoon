/*
	joon - #9095
	1,2,3더하기(Dynamic Programming)
	Coded by NyImo
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define INFI 9999999
int D[INFI]; // dp를 위한 배열
int main(){
	
	int  repet =0;
	cin>>repet;
	int input[repet];
	for(int i=0;i<repet;i++)
		cin>>input[i];
	int cnt=0;
	while(cnt < repet){
		//점화식 : D[N] = D[N-3]+D[N-2]+D[N-1]
		// 초기 setup
		D[1]=1;
		D[2]=2;
		D[3]=4;
		for(int i=4;i<=input[cnt] ; i++){
			D[i]=D[i-3]+D[i-2]+D[i-1];
		}
		cout << D[input[cnt]]<<"\n";
		cnt++;
	}
	return 0;
}