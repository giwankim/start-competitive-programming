#include <iostream>

using namespace std;

int main() {

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    /** Input ***/
    int N;
    cin >> N;
    int X[N];
    int Y[N];

    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }


    int area2 = -1;
    // Do exhuastive search.
    // i - corner
    // j - same X
    // k - same Y
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (X[i] == X[j] && Y[i] == Y[k]) {
                    int tmp = abs(Y[i] - Y[j]) * abs(X[i] - X[k]);
                    if (tmp > area2)
                        area2 = tmp;
                }
            }
        }
    }
    cout << area2;
    return 0;
}
