/*
  #1449-수리공 항승
  Coded by yimo22
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
  int N , L;
  cin >> N >> L;
  int hole[1000];
  for(int i=0;i<N;i++)
    cin >> hole[i];
  
  // 오름차순 정렬
  sort(hole,hole+N);

  int answ = 0;
  int pos = 0;
  while(1){
    int start = hole[pos++];
    while(hole[pos] < start + L )
      pos++;
    
    answ++;
    if(pos >= N)
      break;
  }

  cout << answ << endl;
  
}
