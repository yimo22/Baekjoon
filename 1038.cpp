/*
  joon - #1038
  감소하는 수
  Coded by yimo22
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 1000000
long long dp[MAX + 1]; // dp[x]: x'nd decreasing number
queue<long long> q;
void GetDecNum(int input)
{
  int pos = 10;
  if (input < pos)
    return;
  while (pos <= input)
  {
    long long nextVar;
    if (q.empty())
      return;
    nextVar = q.front();
    q.pop();
    for (int i = 0; i < nextVar % 10; i++)
    {
      dp[pos++] = nextVar * 10 + i;
      q.push(nextVar * 10 + i);
    }
  }
  return;
}
int main()
{
  int N;
  cin >> N;
  // 1022's decreasing number is 9876543210
  if(N < 0 || N > 1022){
    cout << "-1";
    return 0;
  }
  dp[0] = 0;
  for (long long i = 1; i < 10; i++)
  {
    dp[i] = i;
    q.push(i);
  }
  GetDecNum(N);

  cout << dp[N] << endl;
  return 0;
}