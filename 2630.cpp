#include <iostream>

using namespace std;

int N;
int board[128+1][128+1];
int answ[2]={0,0};
void Solved(int x, int y, int length){
  bool Check = false;
  // N정사각형에 대하여 나누지 않아도 되는 경우
  int pivot = board[x][y];
  for(int i=x;i<x+length;i++){
    for(int j=y;j<y+length;j++){
      if(pivot != board[i][j]){
        Check = true;
        break;
      }
    }
    if(Check)
      break;
  }
  if(Check){
    // N정사각형에 대하여 나눠야 하는 경우.
    Solved(x,y,length/2);
    Solved(x+length/2,y,length/2);
    Solved(x,y+length/2,length/2);
    Solved(x+length/2,y+length/2,length/2);
  }
  else{
    // N 사각형에 대하여 나누지 않아도 되는 경우
    answ[pivot]++;
  }
    
    return ;
}
int main(){
  cin >> N;

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++)
      cin >> board[i][j];
  }

  // start 
  Solved(1,1,N);

  // answ
  cout << answ[0] << endl << answ[1] << endl;

  return 0;
}
