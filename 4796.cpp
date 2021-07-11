#include <iostream>
#include <vector>
using namespace std;

int main(){
  int L,P,V;
  vector<int> v;
  while(1){
    cin >> L >> P >> V;
    if(L==0&&P==0&&V==0)
      break;
    
    int answ=0;
    answ = V / P * L;
    int p = V % P;
    answ += min(p,L);
    v.push_back(answ);
  }

  for(int i=0;i<v.size();i++){
    cout << "Case " << i+1 << ": " << v[i] << endl;
  }
}