#include <iostream>

using namespace std;

int main() {

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int c[3];
    int m[3];
    for (int i = 0; i < 3; ++i) {
        cin >> c[i] >> m[i];
    }

    for (int i = 0; i < 100; ++i) {
        int from = i % 3;
        int to = (i + 1) % 3;
        int amt = min(m[from], c[to] - m[to]);
        m[from] -= amt;
        m[to] += amt;
    }

    for (int i = 0; i < 3; ++i) {
        cout << m[i] << endl;
    }
    return 0;
}
