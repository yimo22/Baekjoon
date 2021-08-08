#include <iostream>
#include <algorithm>
#include <queue>
#include <unistd.h>
#include <vector>

#define MAX 300

using namespace std;

vector<int> answ;
queue<pair<int, pair<int,int> > > q;
int T,L;
int brd[MAX][MAX] = {0,};
int visited[MAX][MAX] = {0,};
int dir[8][2] = {
  {2,1},
  {1,2},
  {-1,2},
  {-2,1},
  {-1,-2},
  {-2,-1},
  {2,-1},
  {1,-2},
};
int main(){
  cin >> T;

  while(T>0){
    pair<int,pair<int,int> > start, end;
    start.first = 0;
    end.first = 0;
    cin >> L;
    cin >> start.second.first >> start.second.second >> end.second.first >> end.second.second;
    // reset
    for(int i=0;i<L;i++){
      fill_n(brd[i],L,0);
      fill_n(visited[i],L,0);
    }
    
    while(!q.empty()){
      q.pop();
    }

    q.push(start);
    while(!q.empty()){

      int cur_x = q.front().second.first, cur_y = q.front().second.second, cur_cnt = q.front().first;
      q.pop();
      //cout << cur_x << " " << cur_y  << endl;
      //sleep(1);
      if(visited[cur_x][cur_y])
        continue;

      if(cur_x == end.second.first && cur_y == end.second.second){
        answ.push_back(cur_cnt);
        break;
      }
      // checking visit
      visited[cur_x][cur_y] = 1;

      for(int i=0;i<8;i++){
        int next_x = cur_x + dir[i][0], next_y = cur_y + dir[i][1];
        //cout << "next : " << next_x << " " << next_y << endl;
        //sleep(1);
        if( next_x < 0 || next_x >= L || next_y < 0 || next_y >= L)
          continue;

        q.push(make_pair(cur_cnt + 1, make_pair(next_x, next_y)));
      }
    }


    T--;
  }

  for(int i=0;i<answ.size();i++){
    cout << answ[i] << endl;
  }
}