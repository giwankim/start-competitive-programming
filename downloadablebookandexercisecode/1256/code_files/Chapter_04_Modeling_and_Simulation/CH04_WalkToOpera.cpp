#include <iostream>

using namespace std;

int main() {

    int N = 3;
    int x_end = 8, y_end = 15;
    int x[] = {1, 14, 4};
    int y[] = {4, 6, 8};


    int ans = 0;
    for (int cow = 0; cow < N; ++cow) {
        if (y[cow] > y_end) continue;
        int t_cow = abs(x[cow] - x_end);
        int t_bessie = y[cow];
        if (t_cow <= t_bessie) ans++;
    }

    cout << ans;

    return 0;
}
