#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;
int main(){
  int N;
  vector<int> v;
  int input;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> input ;
    v.push_back(input);
  }
  sort(v.begin(),v.end(),greater<int>());
  vector<int> answ;
  for(int i=0;i<v.size();i++){
    answ.push_back((i+1) * v[i]);
  }
  cout << * max_element(answ.begin(),answ.end()) << endl;
}