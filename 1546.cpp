#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> score;
  for(int i=0;i<N;i++){
    int temp;
    cin >> temp;
    score.push_back(temp);
  }

  int max_score = *max_element(score.begin(),score.end());

  double sum=0;
  for(int i=0;i<N;i++){
    double new_s = (double) score[i]/max_score * 100;
    sum += new_s;
  }
  
  cout << sum / N << endl;

  return 0;
}