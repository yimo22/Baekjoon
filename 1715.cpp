#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;
struct comp{
  bool operator()(int a, int b){
    return a > b;
  }
};

int main(){
  priority_queue<int,vector<int>,comp> pq;

  int N;
  cin >> N;
  for(int i=0;i<N;i++){
    int temp;
    cin >> temp;
    pq.push(temp);
  }
  int val = 0;
  while(pq.size()!=1){
    int p1 = pq.top(); pq.pop();
    int p2 = pq.top(); pq.pop();
    val += (p1+p2);
    pq.push(p1+p2);
  }

  cout << val << endl;

}