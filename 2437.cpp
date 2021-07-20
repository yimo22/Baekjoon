#include <iostream>
#include <vector>

using namespace std;

int v[1000];
  bool isPossible[1000] = {false};
int main(){
  int N;
  cin >> N;

  long long weight = 0;
  for(int i=0;i<N;i++){
    cin >> v[i];
  }

  // start
  long long answ=0;
  while(1){
    answ ++;

    // 가능한지 탐색
    for(int i=1;i<=N;i++){
      // 갯수에 대하여 탐색
      if(isPossible[answ])
        break;
      for(int j=0;j<N;j++){
        if(answ == v[j])

      }
    }
  }

  return 0;
}