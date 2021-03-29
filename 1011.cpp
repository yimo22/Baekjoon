/*
  joon - #1011
  Fly me to the Alpha Centauri
  Coded by yimo22
*/
#include <iostream>
using namespace std;
int DISTANCE;
int COUNT = __INT_MAX__;
void Get_cnt(int dis, int cur_v, int cnt)
{
  //  cout << " dis/cur_v/cnt : " << dis << "/" << cur_v << "/" << cnt << endl;
  if (cnt == 0)
  {
    Get_cnt(dis - 1, 1, cnt + 1);
    return;
  }
  if ((cur_v == 2 || cur_v == 1) && dis == 1)
  {
    if (COUNT > cnt + 1)
      COUNT = cnt + 1;
    return;
  }
  // nonpromising
  else if (COUNT < cnt ||dis < cur_v * (cur_v - 1) / 2 || cur_v <= 0)
  {
    return;
  }
  else
  {
    int next_v = cur_v - 1;
    Get_cnt(dis - next_v, next_v, cnt + 1);
    Get_cnt(dis - cur_v, cur_v, cnt + 1);
    next_v = cur_v + 1;
    Get_cnt(dis - next_v, next_v, cnt + 1);
  }
  return;
}
int main()
{
  int input;
  cin >> input;
  long long start, end;
  for (int i = 0; i < input; i++)
  {
    COUNT = __INT_MAX__;
    cin >> start >> end;
    DISTANCE = end - start;
    Get_cnt(DISTANCE, 0, 0);
    cout << COUNT << endl;
  }

  return 0;
}
