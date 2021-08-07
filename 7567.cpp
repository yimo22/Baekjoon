#include <iostream>
#include <queue>
using namespace std;

int N,M;
const int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int matrix[1000][1000];
int visited[1000][1000];
int answ = 0;
struct Node{
  int x;
  int y;
  int cnt;
};
queue<Node> q;
void Solved(){
  int x,y,cnt;
  while(!q.empty()){
    x = q.front().x;
    y = q.front().y;
    cnt = q.front().cnt;
//    cout << x << " " << y << " " << cnt << endl;
    q.pop();

    if(x < 0 || x >= N || y < 0 || y >= M)
      continue;

    if(visited[x][y])
      continue;
    
    visited[x][y] = 1;
    matrix[x][y] = 1;
    answ = max(answ,cnt);

    Node temp;
    for(int i=0;i<4;i++){
      temp.x = x + dir[i][0];
      temp.y = y + dir[i][1];
      temp.cnt = cnt+1;
      if(matrix[temp.x][temp.y] == 0){
        q.push(temp);
      }
    }
  } 
}
bool isAnsw(){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(matrix[i][j] != -1 && matrix[i][j] != 1){
        return false;
      }
    }
  }
  return true;
}
int main(){
  cin >> M >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> matrix[i][j];
      if(matrix[i][j] == 1){
        Node temp = {i,j,0};
        q.push(temp);
      }
    }
  }

  Solved();
  if(isAnsw())
    cout << answ << endl;
  else
    cout << -1 << endl;
  return 0;
}