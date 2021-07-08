#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string s1, s2;
  cin >> s1 >> s2;
  int cnt = s2.length() - s1.length();
  for(int i=0;i<cnt ;i++){
    if(s2.back() == 'A')
      s2.pop_back();
    else{
      // B일 경우
      s2.pop_back();
      reverse(s2.begin(),s2.end());
    }
  }
  if(s1.compare(s2) == 0)
    cout << 1 << endl;
  else
    cout << 0 << endl;

}