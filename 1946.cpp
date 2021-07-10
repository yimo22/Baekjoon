#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main(){
  int T;
  cin >> T;
  int N,cnt=0;
  vector<int> answ;
  vector< pair<int,int> > v;
  while(T>0){
    cin >> N;
    v.clear();
    for(int i=0;i<N;i++){
      int a,b;
      cin >> a >> b;
      pair<int,int> p = make_pair(a,b);  
      v.push_back(p);    
    }
    // 서류 전형에 대하여 성적순 정렬
    sort(v.begin(),v.end());
    int val = v[0].second;
    // 서류전형 1등은 채용
    cnt = 0;
    cnt++;
    // 최적의 해를 탐색
    for(int i=1;i<N;i++){
      if(val > v[i].second ){
        // 면접전형은 더 잘본 경우
        cnt++;
        val = v[i].second;
      }
    }
    answ.push_back(cnt);

    T--;
  }
  for(int i=0;i<answ.size();i++){
    cout << answ[i] << endl;
  } 
}