#include <iostream>
#include <string>

using namespace std;
int main(){
  string s;
  int dic[26] = {0};
  cin >> s;

  for(int i=0;i<s.size();i++){
    dic[s[i]-'a']++;
  }

  for(int i=0;i<26;i++)
    cout << dic[i] << " ";
}