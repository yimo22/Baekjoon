#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M;
int matrix[100][100]={0,};
int visited[100][100]={0,};
const int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
struct Node{
  int x;
  int y;
  int cnt;
};
queue<Node> q;
int answ = 0;
void Solved(){
  Node temp = {0,0,1};
  q.push(temp);

  while(!q.empty()){
    temp = q.front(); q.pop();
    // 정상 범위가 아닌 경우
    if(temp.x < 0 || temp.x >= N || temp.y <0 || temp.y >=M)
      continue;
    // 방문한경우
    if(visited[temp.x][temp.y])
      continue;
    
    // 정답을 찾은경우
    if(temp.x == N-1 && temp.y == M-1){
      answ = temp.cnt;
      return;  
    }
    // vist loc
    visited[temp.x][temp.y] = 1;
    Node _next;
    // 4가지 방향에 대하여 탐색
    for(int i=0;i<4;i++){
      _next.x = temp.x + dir[i][0];
      _next.y = temp.y + dir[i][1];
      _next.cnt = temp.cnt;
      if(matrix[_next.x][_next.y] == 1){
        _next.cnt++;
        q.push(_next);
      }
    }
  }
}
int main(){
  string s;
  cin >> N >> M;
  for(int i=0;i<N;i++){
    cin >> s;
    for(int j=0;j<M;j++){
      matrix[i][j] = s[j] - '0';
    }
  }

  Solved();

  cout << answ << endl;

  return 0;
}