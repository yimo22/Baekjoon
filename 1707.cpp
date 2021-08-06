#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 20000

using namespace std;
vector<int> mtrx[MAX];
vector<string> answ;
int visited[MAX]={0,};

int T, E, V;
void dfs(int cur, int col){
  visited[cur] = col;

  int next_col;
  if(col == 1)
    next_col = 2;
  else if(col == 2)
    next_col = 1;

  int size = mtrx[cur].size();
  for(int i=0;i<size;i++){
    int _next = mtrx[cur][i];
    if(!visited[_next]){
      dfs(_next,next_col);
    }
  }
  return ;
}
bool isBiPartion(void){
  for(int i=0;i<V;i++){
    int size = mtrx[i].size();
    for(int j=0;j<size;j++){
      int _node = mtrx[i][j];
      if(visited[_node] == visited[i])
        return false;
    }
  }
  return true;
}
void Solved(){
  for(int i=0;i<V;i++)
    dfs(i,1);
  
  return ;
}
int main(){
  cin >> T;

  while(T>0){
    cin >> V >> E;
    // reset
    for(int i=0;i<V;i++){
      mtrx[i].clear();
    }
    fill_n(visited,MAX,0);

    for(int i=0;i<E;i++){
      int s,e;
      cin >> s >> e;
      mtrx[s].push_back(e);
      mtrx[e].push_back(s);
    }

    Solved();

    if(isBiPartion())
      answ.push_back("YES");
    else
      answ.push_back("NO");

    T--;
  }
  for(int i=0;i<answ.size();i++)
    cout << answ[i] << endl;

  return 0;
}
