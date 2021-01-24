/*
	Baekjoon - #1330
	두 수 비교하기
	Coded by Nyimo
*/
#include <iostream>
using namespace std;
bool IsPromising(int input){
	// input이 -10,000 과 10,000 사이인지 check
	return -10000<=input && input < 10000 ? true : false;
}
int main(){
	int input1=0,input2=0;
	cin >> input1 >> input2;
	if(IsPromising(input1) && IsPromising(input2)){
		if(input1 > input2)
			cout << ">\n";
		else if(input1 < input2)
			cout << "<\n";
		else
			cout << "==\n";
	}else{
		cout << "Error\n";
	}
}