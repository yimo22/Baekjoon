#include <iostream>
#include <queue>
using namespace std;

int N,M,H;
const int dir[6][3] = {{0,1,0},{0,0,1},{0,-1,0},{0,0,-1},{1,0,0},{-1,0,0}};
int matrix[100][100][100];
int visited[100][100][100];
int answ = 0;
struct Node{
  int x;
  int y;
  int z;
  int cnt;
};
queue<Node> q;
void Solved(){
  int x,y,z,cnt;
  while(!q.empty()){
    x = q.front().x;
    y = q.front().y;
    z = q.front().z;
    cnt = q.front().cnt;
    q.pop();


    if(visited[z][x][y])
      continue;
    
    visited[z][x][y] = 1;
    matrix[z][x][y] = 1;
    answ = max(answ,cnt);

    Node temp;
    for(int i=0;i<6;i++){
      temp.x = x + dir[i][1];
      temp.y = y + dir[i][2];
      temp.z = z + dir[i][0];
      temp.cnt = cnt+1;
    if(temp.x < 0 || temp.x >= N || temp.y < 0 || temp.y >= M || temp.z < 0 || temp.z >= H)
      continue;

      if(matrix[temp.z][temp.x][temp.y] == 0){
        q.push(temp);
      }
    }
  } 
}
bool isAnsw(){
  for(int z=0;z<H;z++){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(matrix[z][i][j] != -1 && matrix[z][i][j] != 1){
        return false;
      }
    }
  }}
  return true;
}
int main(){
  cin >> M >> N >> H;
  for(int h=0;h<H;h++){
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        cin >> matrix[h][i][j];
        if(matrix[h][i][j] == 1){
          Node temp = {i,j,h,0};
          q.push(temp);
        }
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