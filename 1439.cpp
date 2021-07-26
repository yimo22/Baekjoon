#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  string s;
  cin >> s;
  int cnt[2]={0};
  char pre=s[0];
  for(int i=0;i<s.length();i++){
    if(pre == s[i])
      continue;
    else if(pre == '0'  ){
      cnt[0]++;
      pre = s[i];
    }
    else if(pre == '1'  ){
      cnt[1]++;
      pre = s[i];
    }
  }
  cnt[pre-'0']++;
  cout <<  min(cnt[1],cnt[0]) << endl;
}