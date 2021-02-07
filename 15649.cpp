/*
	Baekjoon#15649
	- N과 M(1)
	- Backtracking
	Coded by yimo22
*/
#include <iostream>
#include <vector>
using namespace std;
#define MAX 8+1

int N=0,M=0;
int arr[MAX];
bool visited[MAX];

void NM(int cnt){
	if( cnt == M){
		for(int i=0;i<M;i++)
			cout << arr[i]<<" ";
		cout <<"\n";
		return ;
	}

	for(int i=1;i<=N;i++){
		if(!visited[i]){
			visited[i] = true;
			arr[cnt] = i;

			NM(cnt+1);
			visited[i]=false;
		}
	}
}
int main(){
	//1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

	// 첫째 줄에 자연수 N과 M이 주어진다. (1<= M <= N <= 8)
	// 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
	//중복되는 수열을 여러 번 출력하면 안되며, 
	//각 수열은 공백으로 구분해서 출력해야 한다.
	//수열은 사전 순으로 증가하는 순서로 출력해야 한다.
	cin >> N >> M;
	if(N<M || M>8 || M < 0 || N > 8 || N < 0)
		// 조건에 맞는 입력값 검사
		cout << "Error\n";
	else{
		NM(0);
	}


}