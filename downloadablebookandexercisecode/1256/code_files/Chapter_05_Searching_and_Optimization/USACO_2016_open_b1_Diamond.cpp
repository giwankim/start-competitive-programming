#include <iostream>

using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int N, K;
    cin >> N >> K;

    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans = 0;
    for (int a0 = 0; a0 < 10000; ++a0) {
        int a1 = a0 + K;
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (A[j] >= a0 && A[j] <= a1)
                cnt++;
        }
        ans = max(ans, cnt);

    }
    cout << ans << endl;

    return 0;
}