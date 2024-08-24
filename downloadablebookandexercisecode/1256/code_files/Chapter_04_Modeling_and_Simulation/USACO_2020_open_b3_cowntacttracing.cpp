#include <iostream>

using namespace std;


int main() {

    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    int N, T;
    cin >> N >> T;

    bool cows_sick[101]; // just to keep in spirit with the next line
    int t[251] = {0}, x[251], y[251]; // if we save it like this, we do not need to sort. Just go over all 250

    char c;
    for (int i = 1; i <= N; ++i) {
        cin >> c;
        cows_sick[i] = (c == '0') ? false : true;
    }

    int tmp;
    for (int i = 0; i < T; ++i) {
        cin >> tmp;
        t[tmp] = 1;
        cin >> x[tmp] >> y[tmp];
    }


    int kmin = 252;
    int kmax = -1;
    bool cows0_option[100] = {false};

    for (int k = 0; k <= 251; ++k) {
        for (int cow0 = 1; cow0 <= N; ++cow0) {
            // simulate the process
            int hoofshake_count[101] = {0};
            bool sick[101] = {false};
            sick[cow0] = true;
            for (int tt = 1; tt <= 250; ++tt) {
                if (t[tt] == 0) continue;
                if (sick[x[tt]]) hoofshake_count[x[tt]]++;
                if (sick[y[tt]]) hoofshake_count[y[tt]]++;
                if ((sick[x[tt]] && hoofshake_count[x[tt]] <= k) ||
                    (sick[y[tt]] && hoofshake_count[y[tt]] <= k)) {
                    sick[y[tt]] = true;
                    sick[x[tt]] = true;
                }
            }

            bool possible = true;
            for (int i = 1; i <= N; ++i) {
                if (sick[i] != cows_sick[i])
                    possible = false;
            }
            if (possible) {
                cows0_option[cow0] = true;
                kmin = min(kmin, k);
                kmax = max(kmax, k);
            }
        }
    }

    int cnt0 = 0;
    for (int i = 1; i <= N; ++i) {
        if (cows0_option[i]) cnt0++;
    }

    if (kmax == 251)
        cout << cnt0 << " " << kmin << " " << "Infinity";
    else
        cout << cnt0 << " " << kmin << " " << kmax;

    return 0;
}
