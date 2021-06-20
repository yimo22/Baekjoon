#include <algorithm>
#include <iostream>
#include <queue>

#define LARGER 0
#define LESS 1
using namespace std;

int result[4852][2];
int val[100][2]={0};
int isvisit[100];
queue<int> q;
void Reset_visit(){
  for(int i=0;i<100;i++){
    isvisit[i] = 0;
  }
}
int bfs(int node, int N,int M, int tag){
  int cnt=0;
  int pivot = 0;
  for(int index=1;index<=M;index++){
    if(tag == LESS && result[index][LARGER] == node){
      q.push(result[index][LESS]);
    }
    if(tag == LARGER && result[index][LESS] == node){
      q.push(result[index][LARGER]);
    }
  }
  Reset_visit();
  while(!q.empty()){
    pivot = q.front();
    q.pop();
    if(isvisit[pivot] == 1)
      continue;
    cnt++;
    isvisit[pivot] = 1;
    for(int i=1;i<=M;i++){
      if(tag == LESS && result[i][0] == pivot ){
        q.push(result[i][1]);
      }
      if(tag == LARGER && result[i][1] == pivot){
        q.push(result[i][0]);
      }
    }
  }
  return cnt;
}
int main(){
  int N , M;
  int answ= 0;
  cin >> N >> M;
  for(int i=1;i<=M;i++)
    cin >> result[i][0] >> result[i][1];
  for(int i=1;i<=N;i++){
    val[i][LESS] = bfs(i,N,M,LESS);
    val[i][LARGER] = bfs(i,N,M,LARGER);
  }
  int limit = N/2;
  for(int i=1;i<=N;i++){
    if(val[i][LESS] > limit || val[i][LARGER] > limit)
      answ++;
  }
  cout << answ << endl;
}