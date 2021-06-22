#include <iostream>
#include <vector>

using namespace std;

int return_bottle_num(int N){
  int cnt = 0;
  while(N != 0){
    if( (N % 2) == 1)
      cnt++;
    N = N/2;
  }
  return cnt;
}
int main()
{
  int N, K;
  cin >> N >> K;

  int cnt = 0;
  int val = N;
  while( K < return_bottle_num(val)){
    val++;
    cnt++;
  }
  cout << cnt << endl;
}