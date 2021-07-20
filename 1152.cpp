#include <string>
#include <iostream>
using namespace std;

int main()
{
  string s;
  getline(cin, s);
  int cnt = 0;
  if (!s.empty())
  {
    if (s.front() == ' ')
    {
      s.erase(s.front());
    }
    if (!s.empty())
    {
      if (s.back() == ' ')
      {
        s.erase(s.end() - 1);
      }
      int pos = s.find(' ');
      while (pos != s.npos)
      {
        cnt++;
        pos = s.find(' ', pos + 1);
      }
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}