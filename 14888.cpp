#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int num[100];
vector<int> answs;
void Solved(int depth, int op_cnt[4],int val){
  if(depth == N-1){
    answs.push_back(val);

    return ;
  }

  for(int i=0;i<4;i++){
    int new_val = 0;
    if(op_cnt[i] > 0){
      switch(i){
        case 0 : new_val = (val + num[depth+1]); break;
        case 1 : new_val = (val - num[depth+1]); break;
        case 2 : new_val = (val * num[depth+1]); break;
        case 3 : new_val = (val / num[depth+1]); break;
        default : break;
      }
      op_cnt[i]--;
      Solved(depth+1,op_cnt,new_val);
      op_cnt[i]++;
    }
  }
}
int main(){
  int operato[4];
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> num[i];
  }
  for(int i=0;i<4;i++){
    cin >> operato[i] ;
  }

  Solved(0,operato,num[0]);
  cout << * max_element(answs.begin(),answs.end()) << endl;
  cout << * min_element(answs.begin(),answs.end()) << endl;
}