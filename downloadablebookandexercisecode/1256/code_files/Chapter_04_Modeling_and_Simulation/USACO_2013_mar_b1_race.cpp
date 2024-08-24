// http://www.usaco.org/index.php?page=viewproblem2&cpid=259

#include <iostream>

using namespace std;

int main() {

    freopen("cowrace.in", "r", stdin);
    freopen("cowrace.out", "w", stdout);

    int B[1000001], E[1000001];

    int N, M;
    cin >> N >> M;

    B[0] = 0;
    int t = 1;

    for (int i = 0; i < N; ++i) {
        int speed, time;
        cin >> speed >> time;
        for (int j = 0; j < time; j++) {
            B[t] = B[t - 1] + speed;
            t++;
        }
    }

    int Tmax = t;

    E[0] = 0;
    t = 1;

    for (int i = 0; i < M; ++i) {
        int speed, time;
        cin >> speed >> time;
        for (int j = 0; j < time; j++) {
            E[t] = E[t - 1] + speed;
            t++;
        }
    }

    int cnt = 0;
    char leader = ' ';
    for (int t = 1; t < Tmax; ++t) {
        if (B[t] > E[t]) {
            if (leader == ' ') {
                leader = 'B';
                continue;
            }
            if (leader == 'B') continue;
            if (leader == 'E') {
                leader = 'B';
                cnt++;
            }
        }
        if (B[t] < E[t]) {
            if (leader == ' ') {
                leader = 'E';
                continue;
            }
            if (leader == 'E') continue;
            if (leader == 'B') {
                leader = 'E';
                cnt++;
            }
        }

    }


    cout << cnt;
    return 0;
}
