#include <iostream>
#include <queue>
#include <unistd.h>
#include <utility>
#define MAX 100000+1
using namespace std;

int N,K;
int visited[MAX] = {0,};
queue<pair<int,int> > q;
int answ = 0;
bool isPossible(int n){
  if( n < 0 || n >= MAX )
    return false;

  return true;
}
void Solved(){

  while(!q.empty()){
    int cur_pos = q.front().first , cnt = q.front().second;
    q.pop();

    //cout << cur_pos << endl;
    //sleep(1);
    if(visited[cur_pos])
      continue;

    if(cur_pos == K){
      answ = cnt;
      break;
    }

    visited[cur_pos] = 1;

    // for 3 ways
    if(isPossible(cur_pos * 2)) 
      q.push(make_pair(cur_pos * 2, cnt+1));
    
    if(isPossible(cur_pos+1))
      q.push(make_pair(cur_pos + 1, cnt+1));

    if(isPossible(cur_pos-1))
      q.push(make_pair(cur_pos - 1, cnt+1));
  }

  return ;
}
int main(){
  cin >> N >> K;
  q.push(make_pair(N,0));

  Solved();

  cout << answ << endl;

  return 0;
}