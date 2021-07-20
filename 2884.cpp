#include <iostream>

using namespace std;

int main(){
  int H , M;
  cin >> H >> M;

  int time = 60 * H + M;
  time -= 45;
  if(time <0)
    time += 60 * 24;
  M = time % 60;
  H = time / 60;

  cout << H << " " << M << endl;
}