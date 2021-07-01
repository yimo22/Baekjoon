#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
  vector<pair<int,int>> v;
  string s1, s2;
  cin >> s1 >> s2;
  int cnt = 0;
  pair<int,int> answ = make_pair(0,0);
  for(int i=0;i<=(s2.length() - s1.length());i++){
    cnt =0;
    string temp = s2.substr(i,s1.length());
    for(int j=0;j<s1.length();j++){
      if(temp[j] == s1[j])
        cnt ++;    
    }
    if(answ.second < cnt){
      answ.first = i;
      answ.second = cnt;
    }
  }

  cout << s1.length() - answ.second << endl;
  return 0;
}