/*
	joon - #1463
	1로 만들기(Dynamic Programming)
	Coded by NyImo
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define INFI 9999999
int D[INFI]; // dp를 위한 배열
int main(){
	int input=0;
	cin>>input;

	// 초기  set up
	D[1] = 0;
	D[2] = 1;
	D[3] = 1;

	// case 1. 3로 나누는 것이 가능한 경우
	// case 2. 2로 나누는 것이 가능한 경우
	// case 3. -1을 해서 하는 경우
	for(int i=4; i<= input ;i++){
		// case1,2가 모두 가능한 경우
		if(i % 3 == 0 && i % 2 == 0)
			D[i] = min(min(D[i/2],D[i/3]),D[i-1]) + 1;
		// case 1만 가능한 경우
		else if(i%3==0){
			D[i] = min(D[i/3],D[i-1])+1;
		}
		// case 2만 가능한 경우
		else if(i%2==0)
			D[i] = min (D[i/2],D[i-1])+1;
		// case 3만 가능한 경우
		else
			D[i] = D[i-1]+1;
	}
	cout << D[input]<<"\n";
	return 0;
}