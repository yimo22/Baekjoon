#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;
vector<string> dic;
int main(){
  string input;
  while(1){
    cin >> input;
    if(input[0] == '-')
      break;
    dic.push_back(input);
  }

  vector<string> brd;
  while(1){
    cin >> input;
    if(input[0] == '#')
      break;

    brd.push_back(input);
  }
  pair<string,int> min_str;
  pair<string,int> max_str;
  int cnt_alphabat[26];
  int temp[26];
  int cnt = 0;
  vector<pair<string,int>> answer;
  while(1){
    if(cnt == brd.size())
      break;
    
    fill_n(cnt_alphabat,26,0);
    // board판에 대하여 해당 알파벳 수 파악
    for(int i=0;i<9;i++){
      cnt_alphabat[ brd[cnt][i] - 'A' ] ++;
    }
    bool isCorrect = true;
    // 모든 dict에 대하여 탐색 - 단어의 갯수가 
    copy(cnt_alphabat,cnt_alphabat+26,temp);
    for(int i=0;i<dic.size();i++){
      for(int j=0;j<dic[i].size();j++){
        if(temp[dic[i][j] - 'A'] <= 0){
          isCorrect = false;
          break;
          }
      }
    }

    cnt++;
  }
}