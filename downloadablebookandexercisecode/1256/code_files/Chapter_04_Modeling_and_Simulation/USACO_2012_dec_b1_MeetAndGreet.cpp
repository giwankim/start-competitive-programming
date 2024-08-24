#include <iostream>

using namespace std;

int main() {

    freopen("greetings.in", "r", stdin);
    freopen("greetings.out", "w", stdout);

    int B, E;
    cin >> B >> E;

    int Bs[1000000 + 1];
    int Es[1000000 + 1];

    int ind = 1;
    Bs[0] = 0;
    for (int i = 1; i <= B; ++i) {
        char c;
        int steps;
        int dir;
        cin >> steps >> c;
        dir = (c == 'L') ? -1 : 1;
        for (int t = 0; t < steps; ++t) {
            Bs[ind] = Bs[ind - 1] + dir;
            ind++;
        }
    }
    int TB = ind;

    ind = 1;
    Es[0] = 0;
    for (int i = 1; i <= E; ++i) {
        char c;
        int steps;
        int dir;
        cin >> steps >> c;
        dir = (c == 'L') ? -1 : 1;
        for (int t = 0; t < steps; ++t) {
            Es[ind] = Es[ind - 1] + dir;
            ind++;
        }
    }
    int TE = ind;
    int ans = 0;
    for (int j = 1; j <= min(TB, TE); ++j) {
        if (Bs[j] == Es[j] && Bs[j - 1] != Es[j - 1]) {
            ans++;
        }
    }

    for (int j = min(TB, TE); j < TE; ++j) {
        if (Bs[TB - 1] == Es[j] && Bs[TB - 1] != Es[j - 1]) {
            ans++;
        }
    }

    for (int j = min(TB, TE); j < TB; ++j) {
        if (Bs[j] == Es[TE - 1] && Bs[j - 1] != Es[TE - 1]) {
            ans++;
        }
    }


    cout << ans;

    return 0;
}
