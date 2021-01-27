/*
	Baekjoon - #11399
	ATM (Greedy Alogrithm)
	Coded by NyImo
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int input=0;
	cin >> input;

	int v[input];
	for(int i=0;i<input;i++)
		cin >> v[i]; 


	if(input <0 || input >1000)
		cout << "Input Error\n";
	else{
		//Greedy 알고리즘 사용을 위한 오름차순 정렬
		sort(v,v+input);
		int sum=0;
		for(int i=0; i<input;i++){
			for(int j=0;j<i;j++)
				sum+=v[j];
			sum+=v[i];
		}
		cout << sum<<"\n";

	}
}