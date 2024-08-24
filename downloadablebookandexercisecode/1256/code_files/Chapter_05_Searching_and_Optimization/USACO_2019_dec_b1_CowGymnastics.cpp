#include <iostream>

using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int K, N;
    cin >> K >> N;

    int data[K][N];
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> data[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            bool flag = true;
            for (int kk = 0; kk < K && flag; ++kk) {
                for (int ll = 0; ll < N && flag; ++ll) {
                    if (data[kk][ll] == (i + 1)) break;
                    if (data[kk][ll] == (j + 1)) flag = false;
                }
            }
            if (flag) count++;
        }
    }

    cout << count;

    return 0;
}