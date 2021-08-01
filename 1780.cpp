#include <iostream>

using namespace std;

int N;
int matrix[2187][2187]; // 3^7 = 2187
int answ[3]={0,0,0};
void Solved(int x,int y,int length){
  int val = matrix[x][y];
  bool Check =false;
  // 순회
  for(int i=x;i<x+length;i++){
    for(int j=y;j<y+length;j++){
      if(matrix[i][j] != val){
        Check = true;
        break;
      }
    }
    if(Check) break;
  }

  if(Check){
    // Divide 해야 하는 경우
    int temp = length/3;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        Solved(x+i*temp,y+j*temp,temp);
      }
    }
  }
  else{
    // Divide 하지 않아도 되는 경우
    answ[val+1]++;
  }
}
int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cin >> matrix[i][j];
  }

  // start
  Solved(0,0,N);

  for(int i=0;i<3;i++)
    cout << answ[i] << endl;
  return 0;
}