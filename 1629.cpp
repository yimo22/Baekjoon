#include <iostream>

using namespace std;

long long A,B,C;
long long answ = 1;
long long Solved(long long a, long long b, long long c){
  if(b==0)
    return 1;

  long long val = Solved(a,b/2,c);
  val = val * val % c;
  if(b % 2 == 0){
    return val;
  }
  else
    return (val * a) % c;
}
int main(){
  cin >> A >> B >> C;
  cout << Solved(A,B,C) << endl;

  return 0;
}