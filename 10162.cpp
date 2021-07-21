/*
  #10162-전자레인지
  Coded by yimo22
*/  
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;

  int time[3];
  // 각 버튼에 대한 시간(sec)
  time[0] = 300;
  time[1] = 60;
  time[2] = 10;

  vector<int> v;
  for(int i=0;i<3;i++){
    v.push_back(N/time[i]);
    N = N%time[i];
  }
  if(N==0){
    for(int i=0;i<v.size();i++){
      cout << v[i] << " ";
    }
  }
  else{
    cout << -1 << endl;
  }
  return 0;
}
