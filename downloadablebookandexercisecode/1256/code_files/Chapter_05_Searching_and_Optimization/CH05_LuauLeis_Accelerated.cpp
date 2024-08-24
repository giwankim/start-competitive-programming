#include <iostream>

using namespace std;

int main() {

    // Sample input
    int N = 7;
    int K = 3;
    int leis[] = {4, 7, 8, 10, 12, 14, 19};


    int num_above = 0;
    int index_above = N;
    int num_below = 0;
    int index_below = 0;
    int extra = 0;

    int m0 = leis[0];
    for (int i = 0; i < N; ++i) {
        if (leis[i] > m0 + K) {
            num_above++;
            index_above = min(index_above, i);
            extra += leis[i] - (m0 + K);
        }
    }

    int min_m;
    int min_extra = INT_MAX;

    for (int m = leis[0] + 1; m <= leis[N - 1]; ++m) {
        while (leis[index_below] < m - K && index_below < N) {
            index_below++;
            num_below++;
        }

        while (leis[index_above] < m + K && index_above < N) {
            index_above++;
            num_above--;
        }

        extra = extra - num_below - num_above;
        if (abs(extra) < min_extra) {
            min_extra = abs(extra);
            min_m = m;
        }
    }

    cout << min_m << endl;
    // cout << endl << "Value of " << min_extra << " achieved at " << min_m;

    return 0;
}
