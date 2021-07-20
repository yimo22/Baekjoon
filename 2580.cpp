/*
  #2480 - 스도쿠
  Coded by yimo22
*/
#include <iostream>
#include <vector>

using namespace std;

bool isPromising(int board[9][9],int row, int col, int val){
  for(int i=0;i<9;i++){
    if(board[row][i] == val) return false;
    if(board[i][col] == val) return false;
  }
  return true;
}
void solved(int board[9][9], int depth){
  if(depth % 3 == 0 && depth != 0){
    bool Check[3][10] = {false};
    // 정사각형에 대하여 검사.
    for(int i = depth -3; i < depth; i++){
      for(int j=0;j<9;j++){
        Check[j/3][board[i][j]] = true;
      }
    }
    for(int i=0;i<3;i++){
      for(int j=1;j<=9;j++){
        if(Check[i][j] == false){
          return ;
        }
      }
    }
  }
  if(depth == 9){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++)
        cout << board[i][j] << " ";
      
      cout << endl;
    }
    return ;
  }

  // 0의 위치를 파악
  vector<int> col;
  for(int i=0;i<9;i++){
    if(board[depth][i] == 0)
      col.push_back(i);
  }

  
}
int main(){
  int board[9][9];
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      cin >> board[i][j];
    }
  }

  solved(board,0);


  return 0;
}