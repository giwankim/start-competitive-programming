#include <iostream>

using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    int road[100];

    int l, s;
    int mile = 0;
    for (int i = 0; i < N; ++i) {
        cin >> l >> s;
        for (int j = 0; j < l; ++j) {
            road[mile++] = s;
        }
    }

    mile = 0;
    int max_speed = 0;
    for (int i = 0; i < M; ++i) {
        cin >> l >> s;
        for (int j = 0; j < l; ++j) {
            max_speed = max(s - road[mile++], max_speed);
        }
    }

    cout << max_speed;
    return 0;
}