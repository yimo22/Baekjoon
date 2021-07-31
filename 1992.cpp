#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAX 64

int board[MAX][MAX];
int N;
vector<char> answ;
void Solved(int x, int y , int length){
  // 시작 주소 (x,y)에 대하여 길이 length인 정사각형을 검사
  bool Check = false;
  int pivot = board[x][y];
  for(int i=x;i < x+length;i++){
    for(int j=y;j < y+length;j++){
      if(pivot != board[i][j]){
        Check = true;
        break;
      }
    }
    if(Check)
      break;
  }

  // Check에 대하여 검사
  if(Check){
    // 하나로 압축이 불가능한 경우
    answ.push_back('(');
    Solved(x,y,length/2);
    Solved(x,y+length/2,length/2);
    Solved(x+length/2,y,length/2);
    Solved(x+length/2,y+length/2,length/2);
  
    answ.push_back(')');
  }
  else{
    // 하나로 압축이 가능한 경우
    answ.push_back(pivot+'0');
  }
}
int main(){
  cin >> N;
  string s;
  for(int i=0;i<N;i++){
    cin >> s;
    for(int j=0;j<N;j++){
      board[i][j] = s[j] - '0';
    }
  }

  Solved(0,0,N);  
  
  // answ
  for(int i=0;i<answ.size();i++){
    cout << answ[i];
  }
  cout << endl;

  return 0;
}