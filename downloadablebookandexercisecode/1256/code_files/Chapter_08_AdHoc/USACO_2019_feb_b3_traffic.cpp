#include <iostream>
#include <limits.h>

using namespace std;

int main() {

    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int N;
    cin >> N;

    string s[N];
    int a[N], b[N];
    for (int i = 0; i < N; ++i)
        cin >> s[i] >> a[i] >> b[i];

    // Go left to right
    // Find minimum and maximum values at the end
    int min_e = 0, max_e = 999999;

    for (int i = 0; i < N; ++i) {
        if (s[i] == "none") {
            min_e = max(min_e, a[i]);
            max_e = min(max_e, b[i]);
        }
        if (s[i] == "on") {
            min_e += a[i];
            max_e += b[i];
        }
        if (s[i] == "off") {
            min_e = max(min_e - b[i], 0);
            max_e -= a[i];
        }
    }

    // find minimum and maximum values at the start in a symmetrical way
    int min_s = 0, max_s = 999999;
    // we can actually start from the end of value
    // which we know to be true:
    // min_s = min_e; max_s = max_e;

    // we need to go backward
    for (int i = N - 1; i >= 0; --i) {
        if (s[i] == "none") {
            min_s = max(min_s, a[i]);
            max_s = min(max_s, b[i]);
        }
        if (s[i] == "on") {
            min_s = max(min_s - b[i], 0);
            max_s -= a[i];
        }
        if (s[i] == "off") {
            min_s += a[i];
            max_s += b[i];
        }
    }


    cout << min_s << " " << max_s << endl;
    cout << min_e << " " << max_e << endl;
    return 0;
}