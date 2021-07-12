#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
  vector<pair<int,int> > v;

  for(int i=0;i<9;i++){
    int input ; 
    cin >> input;
    pair<int,int> p1 = make_pair(input,i+1);
    v.push_back(p1);
  }   
  sort(v.begin(),v.end(),greater<pair<int,int> >());
  cout << v[0].first << endl << v[0].second << endl;

}