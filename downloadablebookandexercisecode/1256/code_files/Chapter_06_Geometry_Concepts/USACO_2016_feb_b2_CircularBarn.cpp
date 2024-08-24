#include <iostream>
#include <climits>

using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n;
    cin >> n;
    int rs[n];

    for (int i = 0; i < n; ++i) {
        cin >> rs[i];
    }

    int min_dist = INT_MAX;
    // loop over all doors
    for (int d = 0; d < n; ++d) {
        // loop over all the rooms
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            // We can skip our 'own' room, but never mind. it will add 0 anyway.
            int dist = i - d;
            if (dist < 0) dist += n;
            sum += dist * rs[i];
        }
        min_dist = min(sum, min_dist);
    }

    cout << min_dist;

    return 0;
}
