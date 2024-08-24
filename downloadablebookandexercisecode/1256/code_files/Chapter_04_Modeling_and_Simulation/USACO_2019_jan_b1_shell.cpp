#include <iostream>

using namespace std;

int main() {

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int N;
    cin >> N;
    int a[N];
    int b[N];
    int g[N];

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> g[i];
    }

    int cnt = 0;

    for (int start = 1; start <= 3; ++start) {
        int p = start;
        int cnt0 = 0;
        for (int i = 0; i < N; ++i) {
            // do the swap
            if (p == a[i]) p = b[i];
            else if (p == b[i]) p = a[i];

            if (g[i] == p) cnt0++;
        }
        if (cnt0 > cnt)
            cnt = cnt0;
    }


    cout << cnt;

    return 0;
}
