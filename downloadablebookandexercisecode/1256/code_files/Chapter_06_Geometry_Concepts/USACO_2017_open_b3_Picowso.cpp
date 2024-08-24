#include <iostream>

using namespace std;

int main() {

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int N;
    cin >> N;

    int pic[N][N];
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; c++) {
            char ch;
            cin >> ch;
            pic[r][c] = ch - '0';
        }
    }

    bool colors[10];
    for (int i = 0; i < 10; ++i) colors[i] = false;

    colors[0] = false;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; c++) {
            int a = pic[r][c];
            colors[a] = true;
        }
    }

    for (int color = 1; color < 10; ++color) {
        // find max/min of rectangle
        int r0 = N, r1 = -1, c0 = N, c1 = -1;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; c++) {
                int a = pic[r][c];
                if (a == color) {
                    r0 = min(r0, r);
                    r1 = max(r1, r);
                    c0 = min(c0, c);
                    c1 = max(c1, c);
                }
            }
        }
        // check there's no other color there
        for (int r = r0; r <= r1; ++r) {
            for (int c = c0; c <= c1; c++) {
                int a = pic[r][c];
                if (a != color) {
                    colors[a] = false;
                }
            }
        }
    }


    int ans = 0;
    for (int color = 1; color < 10; ++color) {
        if (colors[color]) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}
