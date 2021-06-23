#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int N;
  cin >> N;
  int arr[50][50]={0};
  char c;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> c;
      if(c == 'Y')
        arr[i][j] = 1;
    }
  }
  int num_friend[50] = {0};
  for(int person = 0;person < N;person++){
    // 0~N-1 까지 탐색 시작
    for(int i=0;i<N;i++){
      // 같은 사람일경우 pass
      if(person == i )
        continue;
      // person 과 i가 친구 이면 count++
      if(arr[person][i] == 1 ){
        num_friend[person]++;
        continue;
      }
      else{
        // person과 i가 친구가 아닐경우
        for(int j=0;j<N;j++){
          if( j== person || j == i )
            continue;
          // person과 j가 친구이며, i와 j가 친구일경우 person과 i는 친구임
          if(arr[person][j]==1 && arr[i][j] == 1 ){
            num_friend[person]++;
            break;
          }
        }
      }

    }
  }

  cout << * max_element(num_friend,num_friend+N) << endl;

  return 0;
}