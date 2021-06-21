#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
  int N;
  int temp;
  cin >> N;
  vector<int> Crain;
  for (int i = 0; i < N; i++)
  {
    cin >> temp;
    Crain.push_back(temp);
  }
  int M;
  cin >> M;
  vector<int> box;
  for (int i = 0; i < M; i++)
  {
    cin >> temp;
    box.push_back(temp);
  }
  if( * max_element(Crain.begin(),Crain.end()) < *max_element(box.begin(),box.end()) ){
    cout << "-1" << endl;
    exit(0);  
  }
  sort(Crain.begin(), Crain.end());
  //sort(box.begin(), box.end());
  int cnt = 0;
  vector<int>::iterator iter;
  vector<int>::iterator ptr;
  while (!box.empty())
  {
    for (int i = 0; i < N; i++)
    {
      // find maximum boxes that correct to Crain
      int Crain_limit = Crain[i];
      int diff = 1000000;
      for (iter = box.begin(); iter != box.end(); iter++)
      {
        if((Crain_limit - *iter) > 0 &&( Crain_limit - *iter) < diff){
          diff = Crain_limit - *iter;
          ptr = iter;
        }
      }
      if(diff != 1000000)
        box.erase(ptr);
    }
    cnt ++;
  }
  cout << cnt << endl;
  return 0;
}