#include <iostream>

#include <vector>

using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int N = 0;
    cin >> N;

    int X[N];
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }


    int max_cnt = 0;

    for (int i = 0; i < N; ++i) {

        int x0 = X[i];
        int cnt = 1;


        // go to the left
        int xlast = x0;
        int xlast_new = xlast;

        bool explode = true;
        int dist = 1;

        while (explode) {
            explode = false;
            for (int j = 0; j < N; ++j) {
                if (xlast - X[j] <= dist && X[j] < xlast) {
                    explode = true;
                    cnt++;
                    xlast_new = min(X[j], xlast_new);
                }
            }
            xlast = xlast_new;
            dist++;
        }

        // go to the right
        xlast = x0;
        xlast_new = xlast;

        explode = true;
        dist = 1;

        while (explode) {
            explode = false;
            for (int j = 0; j < N; ++j) {
                if (X[j] - xlast <= dist && X[j] > xlast) {
                    explode = true;
                    cnt++;
                    xlast_new = max(X[j], xlast_new);
                }
            }
            xlast = xlast_new;
            dist++;
        }

        max_cnt = max(cnt, max_cnt);

    }

    cout << max_cnt;
    return 0;
}