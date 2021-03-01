/*
	joon - #13460
	구슬 탈출 2 - 삼성SW 기출
	Coded by yimo22
*/	
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int,int> Get_col(string board[], char text){
	int col, row;
	for(int i=0;i<board->size();i++){
		
		if(board[i].find(text) != -1 ){
			row = board[i].find(text);
			break;
		}
		col++;
	}
	return -1;
}
int EscMarble(string board[], int cnt){
	// 왼쪽으로 기울이기, 오른쪽으로 기울이기, 
	//위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.

	// 현재 Red 의 위치를 파악

	// case 1. 왼쪽으로 기울이는 경우


	// case 2. 오른쪽으로 기울이는 경우


	// case 3. 위쪽으로 기울이는 경우
	

	// case 4. 아래쪽으로 기울이는 경우


	return 1;
}
int main(){
	int N , M;
	cin >> N >> M;
	// '.'은 빈 칸을 의미하고, 
	//'#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 
	//'O'는 구멍의 위치를 의미한다. 
	//'R'은 빨간 구슬의 위치, 
	//'B'는 파란 구슬의 위치이다.
	string board[N];
	for(int i=0;i<N;i++){
		cin >> board[i];
	}

	cout << EscMarble(board, 0);
}