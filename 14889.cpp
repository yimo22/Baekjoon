#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int S[20][20];
bool isStart[20]={false};
int answs = 987654321;
void Solved(int depth, int count){
  if(depth > N){
    return  ;
  }
  if(count == N/2){
    int sum_grp = 0, sum_ngrp = 0;
    for(int i=0;i<N-1;i++){
      for(int j=i+1;j<N;j++){
        // i 와 j가 grp1에 속하지 않는 경우
        if(isStart[i] && isStart[j]){
          sum_ngrp += S[i][j];
          sum_ngrp += S[j][i];
        }
        // i와 j가 grp1에 속하는 경우
        if( !isStart[i] && !isStart[j]){
          sum_grp += S[i][j];
          sum_grp += S[j][i];
          
        }
      }
    }
    answs = min(answs,abs(sum_grp - sum_ngrp));

    return ;
  }

  // depth번째 사람을 포함하는 경우
  isStart[depth] = true;
  Solved(depth+1,count+1);
  // depth번째 사람을 포함하지 않는 경우
  isStart[depth] = false;
  Solved(depth+1,count);
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cin >> S[i][j];
  }

  Solved(0,0);

  cout << answs << "\n";

  return 0;
}