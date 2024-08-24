#include <iostream>

#include <climits>

using namespace std;

int main() {

    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    int N;
    cin >> N;
    int h[N];
    int min_h = 100;
    int max_h = 0;

    for (int i = 0; i < N; ++i) {
        cin >> h[i];
        min_h = min(h[i], min_h);
        max_h = max(h[i], max_h);
    }

    int low_h = min_h;
    int high_h = low_h + 17;

    int min_cost = INT_MAX;

    while (high_h <= max_h) {
        int cost = 0;
        for (int i = 0; i < N; ++i) {
            if (h[i] < low_h) {
                cost += (h[i] - low_h) * (h[i] - low_h);
            }
            if (h[i] > high_h) {
                cost += (h[i] - high_h) * (h[i] - high_h);
            }
        }
        min_cost = min(cost, min_cost);
        low_h++;
        high_h++;
    }

    int ans = min_cost;
    cout << ans;

    return 0;
}
