#include <iostream>
#include <set>

using namespace std;

int main(){
  set<int> s;

  for(int i=0;i<10;i++){
    int temp = 0;
    cin >> temp ;
    s.insert(temp % 42);
  }

  cout << s.size() << endl;

  return 0;
}