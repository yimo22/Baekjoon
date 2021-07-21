#include <iostream>
using namespace std;

int N, M;
int arr[8];
void Solved(int depth, int val){
  if(depth == M){
    for(int i= 0;i<M;i++){
      cout << arr[i] << " ";
    }
    cout << "\n";

    return ;
  }

  for(int i=val;i<=N;i++){
    arr[depth] = i;
    Solved(depth+1,i);
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;

  Solved(0,1);
}