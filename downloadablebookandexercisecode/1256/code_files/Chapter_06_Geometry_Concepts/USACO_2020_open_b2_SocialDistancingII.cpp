//http://usaco.org/index.php?page=viewproblem2&cpid=1036

#include <iostream>

using namespace std;

int main() {

    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);

    int N;
    cin >> N;

    int MaxX = 1000001;
    int X[MaxX];
    for (int i = 0; i < 1000001; ++i) X[i] = -1;

    for (int i = 0; i < N; ++i) {
        int x, s;
        cin >> x >> s;
        X[x] = s; // 0- healthy, 1-sick , -1-no cow
    }

    // find R
    int R = 1000001 + 1;
    int status = -1;
    int lastx = 0;
    for (int i = 0; i < MaxX; i++) {
        if (X[i] == -1) continue;
        if (status == -1) {
            status = X[i];
            lastx = i;
            continue;
        }
        if (X[i] != status) {
            int dist = i - lastx;
            R = min(dist - 1, R);
            status = X[i];
            lastx = i;
            continue;
        }
        if (X[i] == status) {
            lastx = i;
            continue;
        }
    }
    int cnt = 0;

    status = -1;
    lastx = -(R + 1);
    for (int i = 0; i < MaxX; i++) {
        if (X[i] != 1) continue;
        if (status == -1) {
            cnt++;
            lastx = i;
            status = 1;
            continue;
        }
        if (X[i] == 1) {
            if (i - lastx > R) cnt++;
            lastx = i;
            continue;
        }

    }

    cout << cnt;
    return 0;
}
