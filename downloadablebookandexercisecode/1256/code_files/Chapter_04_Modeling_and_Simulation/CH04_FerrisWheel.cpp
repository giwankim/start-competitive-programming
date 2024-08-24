#include <iostream>

using namespace std;

int main() {

    int N = 3;
    int K = 8;

    int new_arrivals[] = {2, 7, 0, 5, 5, 2, 5, 1};

    int tub[N];
    for (int i = 0; i < N; ++i) tub[i] = 0;

    int waiting = 0;
    for (int k = 0; k < K; ++k) {
        int tub_at_bottom = k % N;
        int total = waiting + new_arrivals[k];
        if (total > 0) {
            tub[tub_at_bottom] = min(total, 4);
            waiting = max(total - 4, 0);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += tub[i];
    }

    cout << ans << endl;

    return 0;
}
