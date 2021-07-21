#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int S[20][20];
vector<int> answs;
void Solved(int depth, vector<int> grp1){
  if(depth == N){
    int sum_grp = 0, sum_ngrp = 0;
    for(int i=0;i<N-1;i++){
      for(int j=i+1;j<N;j++){
        // i 와 j가 grp1에 속하지 않는 경우
        if(find(grp1.begin(),grp1.end(),i) != grp1.end() && find(grp1.begin(),grp1.end(),j) != grp1.end()){
          sum_ngrp += S[i][j];
          sum_ngrp += S[j][i];
        }
        // i와 j가 grp1에 속하는 경우
        if(find(grp1.begin(),grp1.end(),i) == grp1.end() && find(grp1.begin(),grp1.end(),j) == grp1.end()){
          sum_grp += S[i][j];
          sum_grp += S[j][i];
          
        }
      }
    }
    answs.push_back(abs(sum_grp - sum_ngrp));

    return ;
  }

  // depth번째 사람을 포함하는 경우
  grp1.push_back(depth);
  Solved(depth+1,grp1);
  // depth번째 사람을 포함하지 않는 경우
  grp1.pop_back();
  Solved(depth+1,grp1);
}
int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      cin >> S[i][j];
  }
  vector<int> temp;
  temp.clear();
  Solved(0,temp);

  cout << * min_element(answs.begin(),answs.end()) << endl;

  return 0;
}