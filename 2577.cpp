#include <iostream>

using namespace std;

int main() {
    long long A, B, C;
    long long answ;
    int cnt[10] = {0};
    cin >> A >> B >> C;
    answ = A * B * C;
    while (answ != 0) {
      cnt[answ % 10]++;
      answ = answ / 10;
    }
    
    for(int i=0;i<10;i++){
      cout << cnt[i]<< endl;
    }

    return 0;
}