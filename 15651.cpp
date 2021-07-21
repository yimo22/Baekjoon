#include <iostream>
using namespace std;

int N, M;
int arr[7];

void solved(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        // endl 을 "\n"으로 바꾸니 시간초과가 뜨지 않는다.
        cout << endl;

        return;
    }
    for (int i = 1; i <= N; i++) {
        arr[depth] = i;
        solved(depth + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    solved(0);

    return 0;
}