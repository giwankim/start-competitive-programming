// http://usaco.org/index.php?page=viewproblem2&cpid=487

#include <iostream>

using namespace std;

int main() {

    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);

    int N;
    cin >> N;
    int x[N];
    int y[N];
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
    }

    int d1 = abs(x[1] - x[0]) + abs(y[1] - y[0]);
    int d_total = d1;

    int max_d_saved = 0;
    for (int i = 1; i < N - 1; ++i) {
        int d12 = abs(x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1]);
        int d2 = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
        int d_saved = (d1 + d2) - d12;
        if (d_saved > max_d_saved) {
            max_d_saved = d_saved;
        }
        d_total += d2;
        d1 = d2;
    }

    int ans = d_total - max_d_saved;

    cout << ans;

    return 0;
}
