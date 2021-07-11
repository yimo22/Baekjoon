#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
  int N , K;
  int answ=0;
struct gem{
  int W;
  int V;
  double rate;
}gem;
struct bag{
  int W=0;
  int val=0;
  int Possible_val = 0;
};
bool comp(struct gem g1, struct gem g2){
  if(g1.rate == g2.rate)
    return  g1.W < g2.W;
  else
    return g1.rate < g2.rate;
}
vector<struct gem> g;
void Solved(int depth,struct bag b1){
  // 이후 모든 gem을 더해도 answ보다 크지않을경우 종료
  if(b1.Possible_val < answ )
    return;
  
  // 해당 gem 을 택하면 가방의 무게가 over 되는 경우
  if(b1.W + g[depth].W > K || depth >= N){
    if(b1.val > answ)
      answ = b1.val;

    return;
  }

  b1.Possible_val -= g[depth].V;
  // g[i] 를 택하지 않은 경우
  Solved(depth+1,b1);

  // g[i]를 택하는 경우
  b1.val += g[depth].V;
  b1.W += g[depth].W;
  b1.Possible_val += g[depth].V;
  Solved(depth+1,b1);


  return ;
}
int main(){
  cin >> N >> K;

  struct bag temp;
  for(int i=0;i<N;i++){
    cin >> gem.W >> gem.V;
    gem.rate = (double) gem.W / gem.V;
    temp.Possible_val+= gem.V;
    g.push_back(gem);
  }
  // rate가 높은 순으로 정렬
  sort(g.begin(),g.end(),comp);
  Solved(0,temp);

  cout << answ << endl;
}