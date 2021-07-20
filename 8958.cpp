#include <iostream>
#include <string>

using namespace std;

int main(){
  int N, score;
  string answ;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> answ;
    score = 0;
    int val = 1;
    for(int j=answ.size();j>=0;j--){
      if(answ[j] == 'O'){
        score += val;
        val++;
      }
      else{
        val = 1;
      }
    }
    cout << score << endl;
  }

  return 0;
}