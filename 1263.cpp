#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
bool mysort(pair<int,int> v1, pair<int,int> v2){
  // si 대하여 내림차순 정렬
  return v1.second > v2.second;
}
int main() {
    int N;
    cin >> N;
    int total_time=0;
    pair<int, int> time;
    vector<pair<int, int> > v;
    for (int i = 0; i < N; i++) {
        cin >> time.first >> time.second;
        total_time += time.first;
        v.push_back(time);
    }
    // Si 시에 대하여 정렬
    sort(v.begin(),v.end(),mysort);

    if(v.front().second < total_time){
      cout << -1 << endl;
      return 0;
    }
    int answ = v.front().second - v.front().first;
    v.erase(v.begin());
    // 역순으로 시간을 쓰면서 모든 일을 다 할때까지 반복
    while(!v.empty()){
      answ = min(answ, v.front().second);
      answ -= v.front().first;
      v.erase(v.begin());
    }

    cout << ( (answ < 0) ? -1 : answ) << endl;
    

    return 0;
}