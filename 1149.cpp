/*
    joon - #1149
    RGB거리
    Coded by yimo22
*/
#include <iostream>
#include <algorithm>

using namespace std;

#define R 0
#define G 1
#define B 2
#define MAX 1000
int N;

// DP[i][j] : i번째 집을 j의 색으로 칠했을때의 최소비용
int DP[MAX + 1][3] = {0,};
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> DP[i][R] >> DP[i][G] >> DP[i][B];

        DP[i][R] += min(DP[i - 1][B], DP[i - 1][G]);
        DP[i][G] += min(DP[i - 1][R], DP[i - 1][B]);
        DP[i][B] += min(DP[i - 1][R], DP[i - 1][G]);
    }
    cout << min(DP[N][R], min(DP[N][G], DP[N][B]));

    return 0;
}