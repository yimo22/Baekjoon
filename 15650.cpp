#include <iostream>
#include <deque>

using namespace std;
int N ,M;
void solved(int val, deque<int> v){
  if(v.size() == M){
    for(int i=0;i<M;i++){
      cout << v[i] << " ";
    }
    cout << endl;
    return ;
  }
  if(val > N)
    return ;
  v.push_back(val);
  solved(val+1,v);
  v.pop_back();
  solved(val+1,v);
}
int main(){
  cin >> N >> M;
  deque<int> temp;
  temp.clear();
  solved(1,temp);
}