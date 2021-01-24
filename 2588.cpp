/*
	Baekjoon - #2588
	Date : 1/24/2021
	Coded by Nyimo
*/
#include <iostream>
using namespace std;

int main(){
	// input1,input2 는 세자리 자연수
	int input1=0, input2=0;
	cin >> input1;
	cin >> input2;
	int temp = input2; 
	for(int i=0; i<3; i++){
		cout << input1 * (temp % 10)<<"\n";
		temp /= 10; 
	}
	cout << input1 * input2;

	return 0;

}
