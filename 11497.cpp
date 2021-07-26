#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main(){
  int T;
  cin >> T;
  vector<int> answs;
  while(T>0){
    int N;
    cin >> N;
    deque<int> q;
    vector<int> v;
    for(int i=0;i<N;i++){
      int temp;
      cin >> temp;
      v.push_back(temp);
    }
    sort(v.begin(),v.end(),greater<int>());

    for(int i=0;i<N;i++){
      int val = v.front(); v.erase(v.begin());
      if(i%2 != 0){
        q.push_back(val);
      }
      else{
        q.push_front(val);
      }
    }
    int answ = 0;
    for(int i=0;i<N;i++){
      if(i==N-1){
        answ = max(answ, abs(q[i]-q[0]));
        break;
      }
      answ = max(answ,abs(q[i]-q[i+1]));
    }
    answs.push_back(answ);
    T--;
  }

  for(int i=0;i<answs.size();i++)
    cout << answs[i] << endl;
}