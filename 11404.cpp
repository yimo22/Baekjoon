#include <iostream>
#include <algorithm>
#define MAX (100000+1) * 100
using namespace std;

int matrix[100][100]={0,};
int N, M;
int answ[100][100] = {0,};
void Solved(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if( i==j)
        continue;
      for(int k=0;k<N;k++){
        answ[i][j] = min(answ[i][j], answ[i][k] + matrix[k][j]);
      }
    }
  }
}
int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      matrix[i][j] = answ[i][j] = MAX;
    }
  }
  for(int i=0;i<M;i++){
    int s,e,v;
    cin >> s >> e >> v;
    answ[s-1][e-1] = matrix[s-1][e-1] = min(v,matrix[s-1][e-1]);
  }

  for(int i=0;i<N;i++)
    Solved();

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(answ[i][j] == MAX)
        cout << 0 << " ";
      else
        cout << answ[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}