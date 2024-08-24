#include <iostream>

using namespace std;

int main() {

    // Sample input
    int N = 7;
    int K = 3;
    int leis[] = {4, 7, 8, 10, 12, 14, 19};


    int min_m;
    int min_extra = INT_MAX;

    for (int m = leis[0] + 1; m <= leis[N - 1] - 1; ++m) {
        int extra = 0;
        for (int i = 0; i < N; ++i) {
            if (leis[i] < m - K) {
                extra += leis[i] - (m - K); // negative number, missing flowers
            }
            if (leis[i] > m + K) {
                extra += leis[i] - (m + K); // positive number, extra flwoers
            }
        }

        extra = abs(extra);
        if (extra < min_extra) {
            min_extra = extra;
            min_m = m;
        }
    }

    cout << min_m << endl;
    // cout << endl << "Value of " << min_extra << " achieved at " << min_m;

    return 0;
}
