#include <iostream>

using namespace std;

int main() {

    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);


    int L, N, rf, rb;

    cin >> L >> N >> rf >> rb;

    int x[N], c[N];
    for (int i = 0; i < N; ++i)
        cin >> x[i] >> c[i];

    bool rmc[N]; // Right Maximum C
    int max = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (c[i] > max) {
            rmc[i] = true;
            max = c[i];
        } else rmc[i] = false;
    }

    int lastx = 0;
    long val = 0;
    long dv = rf - rb; // 10^6 *10^6 will be larger than 2*10^10
    for (int i = 0; i < N; ++i) {
        if (rmc[i]) {
            long dt = (x[i] - lastx) * dv;
            val += dt * c[i];
            lastx = x[i];
        }
    }

    cout << val;

    return 0;
}
