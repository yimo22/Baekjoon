/*
	Baekjoon - #2839
	설탕배달 (Greedy Alogrithm)
	Coded by NyImo
*/
#include <iostream>
using namespace std;
void Greedy (int res){

}
int main(){
	// 가장 적은 봉지 사용.
	int input=0;
	int Num_3 = 0;
	int Num_5=0;
	cin >> input;
	if(input < 3 || input > 50000)
		cout << "Error\n";
	else{
		while(input > 0){
			if(input % 5 == 0){
				input -= 5;
				Num_5++;
			}
			else if(input%3==0){
				input -= 3;
				Num_3++;
			}
			else if(input > 5){
				input -= 5;
				Num_5++;
			}
			else{
				cout << "-1\n";
				return 0;
			}
		}
		cout << Num_5+Num_3<<"\n";
	}
}