#include <iostream>
#include <cmath>

using namespace std;

int solve(int k, int x) {

    //Just model the problem
    int dup = 0; // ascending phase
    int ddown = 0; // descending phase
    int t = 0; // time
    int v = 0; // speed
    while (dup + ddown < k) {
        v++;
        dup += v;
        t++;
        if (dup + ddown >= k) continue;
        if (v >= x) { // we have a descending phase
            ddown += v;
            t++;
        }
    }
    return t;

}


int main() {

    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int k, n;
    cin >> k >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cout << solve(k, x) << endl;
    }

    return 0;
}
