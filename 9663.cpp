/*
  #9663(N-Queen)
  Coded by yimo22
*/

#include <iostream>
#include <vector>
#include <cmath>

int N ;
int answ = 0;
using namespace std;

bool isPromising(vector<int> brd){
  // 대각선에 존재 or 같은 열에 존재할경우 유망하지 않음
  int row = brd.size()-1;
  int col = brd.back();
  for(int i=0;i<row ;i++){
    if( abs(brd[i] - col)  == abs(i-row) || col == brd[i] )
      return false;
  }
  return true;
}
void solved(vector<int> board, int depth){

  int cnt = 0;
  if( depth == N){
    answ++;
    return ;
  }
  
  for(int i=0;i<N;i++){
    board.push_back(i);
    if(isPromising(board))
      solved(board,depth+1);
    board.pop_back();
  }
  return ;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;

  vector<int>  v;
  solved(v,0);
  cout << answ << endl;
}