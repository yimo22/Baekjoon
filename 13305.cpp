#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

long long city[100000];
long long dis[100000];
int main(){
  int N;
  cin >> N;

  for(int i=1;i<N;i++){
    scanf("%lld",&dis[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%lld",&city[i]);
  }


  // start
  long long len = 0;
  long long answ = 0;
  long long cur_city = 0;
  for(int i=1;i<N;i++){
    len += dis[i];
    if((city[i] < city[cur_city]) || (i == N-1)){
      //cout << len << " " << i << endl;
      answ += city[cur_city] * len;
      cur_city = i;
      len = 0;
    }

    
  }

  cout << answ << endl;
}