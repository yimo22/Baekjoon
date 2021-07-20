#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ptr[1000000];

    for (int i = 0; i < N; i++) {
        scanf("%d", &ptr[i]);
    }

    cout << *min_element(ptr, ptr + N) << " " << *max_element(ptr, ptr + N)
         << endl;
    return 0;
}