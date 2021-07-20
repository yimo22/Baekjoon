#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main(){
  int N;
  cin >> N;
  
  pair<int,int> p1;
  vector<pair<int,int> > v;
  priority_queue<pair<int,int> , vector<pair<int,int> >> pq;
  for(int i=0;i<N;i++){
    cin >> p1.first >> p1.second;
    v.push_back(p1);
  }

  for(int i=0;i<N;i++){
    
  }
}