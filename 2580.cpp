/*
  #2480 - 스도쿠
  Coded by yimo22
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int,int> > list;
bool isPromising(int row , int col , int val){
  int sub_col = col / 3, sub_row = row / 3;
  
  // row & col 검사
  for(int i=0;i<9;i++){
    // row에 대하여 검사
    if(board[row][i] == val) return false;
    // col에 대하여 검사
    if(board[i][col] == val) return false;
  }

  // sub_square에 대하여 검사
  for(int i= sub_row * 3 ; i<sub_row*3 + 3;i++){
    for(int j=sub_col * 3;j<sub_col*3 + 3;j++){
      if(board[i][j] == val){
        return false;
      }
    }
  }
  return true;
}
void solved(int depth){
  if(depth == list.size()){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout << board[i][j] << " ";
      }
      cout << endl;
    }

    exit(0);
  }

  // start
  for(int num = 1;num<=9;num++){
    int x_pos = list[depth].first;
    int y_pos = list[depth].second;
    if(isPromising(x_pos,y_pos,num)){
      board[x_pos][y_pos] = num;
      solved(depth+1);
      board[x_pos][y_pos] = 0;
    }
  }
}
int main(){

  // input board
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cin >> board[i][j];
      if(board[i][j] == 0){
        list.push_back(make_pair(i,j));
      }
    }
  }
  
  // solved
  solved(0);
  return 0;
}