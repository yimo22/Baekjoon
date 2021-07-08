#include <iostream>
using namespace std;
int main() {
    long long n;
    long long ans = 0;
    long long sum = 0;
    cin >> n;
    for (long long i = 1; sum < n; i++)
    {
        if (sum + i <= n)
        {
            sum += i;
            ans++;
        }
        if(sum + i > n)
        {
            cout << ans << '\n';
            break;
        }
    }
}