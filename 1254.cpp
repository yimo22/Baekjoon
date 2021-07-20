#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;
int map[101][71]={0};
  int N , M;
bool isChecked[101][71] ={false,};
bool isPeak = true;
const int dir[8][2] ={ {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
void dfs(int x, int y){
  for(int i=0;i<8;i++){
    int nx = x + dir[i][0];
    int ny = y + dir[i][1];

    if(nx < 0 || ny >= N || nx < 0 || nx >= M)  continue;

    if( map[nx][ny] > map[x][y]) isPeak = false;

    if( isChecked[nx][ny] || map[x][y] != map[nx][ny]) continue;
    isChecked[nx][ny] = true;
    dfs(nx,ny);
  }
  return ;
}
int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      cin >> map[i][j];
  int cnt = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if( isChecked[i][j] == false){
        isPeak = true;
        dfs(i,j);
        if(isPeak) cnt ++;
      }
    }
  }
  cout << cnt << endl;
}