#include <iostream>

using namespace std;


int matrix[100][100]={0,};
int visited[100]={0,};
int N,E;
int answ = 0;
void dfs(int Node){
  visited[Node] = 1;
  answ++;

  for(int i=0;i<N;i++){
    if(matrix[Node][i] == 1 && !visited[i]){
      dfs(i);
    }
  }
  return ;
}
void Solved(){
  dfs(0);
}
int main(){
  cin >> N;
  cin >> E;

  for(int i=0;i<E;i++){
    int s, e;
    cin >> s >> e;
    matrix[e-1][s-1] = matrix[s-1][e-1] = 1;
  }

  Solved();

  // 1번 컴퓨터의 갯수는 뺀다.
  cout << answ -1 << endl;
  return 0;
}