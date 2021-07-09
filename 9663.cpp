/*
  #9663(N-Queen)
  Coded by yimo22
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int N ;
int answ = 0;
int board[15];
using namespace std;

bool isPromising(int depth){
  // 대각선에 존재 or 같은 열에 존재할경우 유망하지 않음
  int row = depth;
  int col = board[depth];

  for(int i=0;i<row ;i++){
    if( abs(board[i] - col)  == (row-i) || col == board[i] )
      return false;
  }
  return true;
}
void solved( int depth){
  // board는 [0,N) 임.
  int cnt = 0;
  if( depth == N){
    answ++;
    return ;
  }
  
  for(int i=0;i<N;i++){
    board[depth] = i;
    // 유망할 경우
    if(isPromising(depth))
      solved(depth+1);
  }
  return ;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;

  // v[i]= j , i행 일떄의 열값이 j임.
  solved(0);
  cout << answ << endl;
}