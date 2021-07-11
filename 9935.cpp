#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string s1="", bomb="";
  cin >> s1 >> bomb;
  
  while(1){
    int pos = s1.find(bomb);
    if(s1.find(bomb) == string::npos)
      break;
    s1 = s1.substr(0,pos) + s1.substr(pos+bomb.length());
  }
  if(s1.length() == 0)
    cout << "FRULA" << endl;
  else
    cout << s1 << endl;
  return 0;
}