#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int dic[8+1][26] = {0};

int main(){

  int N;
  cin >> N;
  string s;
  int max_len = 0;
  for(int i=0;i<N;i++){
    cin >> s;
    if(max_len < s.length())
      max_len = s.length();
    for(int j=0;j<s.size();j++)
      dic[j+1][s[j] - 'A']++;
    
  }
  cout << "finished" << endl;
  for(int i=1;i<=max_len;i++){
    for(int j=0;j<26;j++)
      cout << dic[i][j] << " ";
    cout << endl;
  }
  int num = 9;
  int answ = 0;
  bool isCheck[26] = {false};
  int pos = 0;
  for (int i = max_len; i > 0; i--) {
      pos = (max_element(dic[i], dic[i] + 26) - dic[i]);
      // 각 자리수에 대하여 합을 구한다.
      for (int i = 1; i <= max_len; i++) {
          answ += dic[i][pos] * pow(10, i-1) * num;
          dic[i][pos] = -1;
      }
      num --;
  }

  cout << answ << endl;

  return 0;
}