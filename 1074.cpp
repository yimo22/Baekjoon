#include <iostream>
#include <cmath>
using namespace std;

int N,r,c;
int result;

int main(){
  cin >> N >> r >> c;

  while(N){
    int idx;
    int length = pow(2,N) / 2;
    // 2사분면
    if(c<length && r < length) idx=0;
    // 1사분면
    else if(c >= length && r < length) idx = 1;
    // 3사분면
    else if( c < length && r>= length) idx=2;
    // 4사분면
    else if( c >= length && r >= length) idx = 3;

    c %= length;
    r %= length;

    result += pow(length,2) * idx;
    N--;
  }

  cout << result << endl;

  return 0;
}