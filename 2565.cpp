#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,answ = 1;
int dp[100];
int main(){
  cin >> N;
  vector<pair<int,int> > v;
  for(int i=0;i<N;i++){
    int x,y;
    cin >> x >> y;
    v.push_back(make_pair(x,y));
  }

  // sort v[].first with increase
  sort(v.begin(),v.end());

  // v[].second 에 대하여 LIS 알고리즘 수행
  // 없애야하는 전깃줄의 최소 = N - (새울수 있는 전깃줄의 최대 수)
  fill_n(dp,100,1);
  for(int i=0;i<N;i++){
    for(int j=i-1;j>=0;j--){
      if(v[j].second < v[i].second){
        dp[i] = max(dp[i],dp[j]+1);
      }
    }
    answ = max(answ,dp[i]);
  }

  cout << N - answ << endl;

  return 0;
}  