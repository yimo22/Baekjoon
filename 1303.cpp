#include <iostream>
#include <cmath>

using namespace std;
int N, M;
int map[100][100] = {0};
int isVisit[100][100] = {0};
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, -1}, {0, -1}};
int bfs(int x, int y)
{
  int cnt = 0;
  cout << "found " << x << "/" << y << endl;
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dir[i][0];
    int ny = y + dir[i][1];

    // 범위를 벗어나는 경우
    if (nx < 0 || nx >= M || ny < 0 || ny >= N)
      continue;

    // 아군인지 적군인지 확인.
    if (map[nx][ny] != map[x][y] || isVisit[nx][ny])
      continue;

    cnt++;
    isVisit[nx][ny] = 1;
    cnt += bfs(nx, ny);
  }
  return cnt;
}
int main()
{
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  char c;
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> c;
      if (c == 'W')
      {
        map[i][j] = 1;
      }
    }
  }
  int cnt_W = 0, cnt_B = 0;
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (!isVisit[i][j])
      {
        isVisit[i][j] = 1;
        // 아군일경우
        if (map[i][j])
          cnt_W += pow((bfs(i, j) + 1), 2);
        else
          cnt_B += pow((bfs(i, j) + 1), 2);
      }
    }
  }
  cout << cnt_W << " " << cnt_B << endl;

  return 0;
}