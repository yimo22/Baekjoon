#include <iostream>
#include <string>
#include <queue>

using namespace std;
#define X 0
#define Y 1
int N,M;
int map[1000][1000];
int visited[2][1000][1000]={0};
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1}};
struct Node{
  int x;
  int y;
  int cnt;
  bool _isBreak;
}Node;
int answ = -1;
void Solved(){
  queue<struct Node> q;
  struct Node temp;
  // 초기값 입력
  temp.x = 0;
  temp.y = 0;
  temp.cnt = 1;
  temp._isBreak = false;
  q.push(temp);

  // start
  while(!q.empty()){
    temp = q.front(); q.pop();
    if(visited[temp._isBreak][temp.x][temp.y])
      continue;
    visited[temp._isBreak][temp.x][temp.y] = 1;
    if(temp.x == N-1 && temp.y == M-1){
      if(answ == -1)
        answ = temp.cnt;
      else{
        answ = max(answ,temp.cnt);
      }
      break;
    }
      
    // for 4 direction.
    for(int i=0;i<4;i++){
      int next_x = temp.x + dir[i][X];
      int next_y = temp.y + dir[i][Y];
      // 해당 범위를 벗어나는 경우
      if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
        continue;
      
        // 이미 벽을 한번 뚫은 경우. & 앞에 벽이 있을경우
      if(temp._isBreak && map[next_x][next_y] == 1)
        continue;
      
        struct Node next_pos;
        next_pos.x = next_x;
        next_pos.y = next_y;
        next_pos.cnt = temp.cnt + 1 ;
        next_pos._isBreak = temp._isBreak;
      if(!temp._isBreak && map[next_x][next_y] == 1){
        // 벽을 뚫는게 가능하고, 벽이 있을 경우.
        next_pos._isBreak = true;
      }
        q.push(next_pos);
    }
  }
}
int main(){
  string s;
  cin >> N >> M;
  for(int i=0;i<N;i++){
    cin >> s;
    for(int j=0;j<M;j++){
      map[i][j] = s[j] - '0';
    }
  }

  Solved();

  cout << answ << endl;

  return 0;
}