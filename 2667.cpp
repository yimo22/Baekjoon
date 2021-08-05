#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> answ;
int N;
int matrix[25][25];
int num_answ = 0;
int visited[25][25] = {0,};
const int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x , int y){
  // visited
  visited[x][y]=1;
  
  // for all dir
  for(int i=0;i<4;i++){
    int next_x = x + dir[i][0];
    int next_y = y + dir[i][1];
    if( next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
      continue;
    if(matrix[next_x][next_y] == 1 && !visited[next_x][next_y]){
      answ[num_answ]++;
      dfs(next_x,next_y);
    }
  }

  return ;
}
void Solved(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(!visited[i][j] && matrix[i][j]==1){
          answ.push_back(1);
          dfs(i,j);
          num_answ++;
      }
      else{
        visited[i][j] = 1;
      }
    }
  }
  return ;
}
int main(){
  string s;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> s;
    for(int j=0;j<N;j++)
      matrix[i][j] = s[j]-'0';
  }

  Solved();

  cout << answ.size() << endl;
  // 답을 오름차순 정렬
  sort(answ.begin(),answ.end());
  for(int i=0;i<answ.size();i++)
    cout << answ[i] << endl;
}