#include <iostream>

using namespace std;


int main() {

    int N, M, S;
    cin >> N >> M >> S;

    const int MAX_TIME = N + 1;  // would be useful to have this. Everything will.
    // surely be done by this time.

    int x_m[M], y_m[M];
    int time_active_m[M];
    for (int i = 0; i < M; ++i) {
        cin >> x_m[i] >> y_m[i];
        time_active_m[i] = MAX_TIME;
    }
    int x_s[S], y_s[S];
    int time_active_s[S];
    for (int i = 0; i < S; ++i) {
        cin >> x_s[i] >> y_s[i];
        time_active_s[i] = MAX_TIME;
    }

    // find all possible interaction times
    // Keep in mind: Some of these will not happen
    // We can use arrays of size M*S:
    // time, moonnow and shark for the interactions
    int t[M * S], moonnow[M * S], shark[M * S]; 
    int times_counter = 0;
    for (int m = 0; m < M; ++m) {
        for (int s = 0; s < S; ++s) {
            if (x_s[s] <= x_m[m] && y_m[m] <= y_s[s]) {
                int dt = min(x_m[m] - x_s[s], y_s[s] - y_m[m]);
                t[times_counter] = dt;
                moonnow[times_counter] = m;
                shark[times_counter] = s;
                times_counter++;
            }
        }
    }

    int total_times = times_counter;

    // Now, progress every step up to the next important point, 
    // and check what happens there.
    while (times_counter > 0) {

        // Find the next closest time instance. 
        // We could have used sort() before, but wanted to avoid this here.
        // See python for easy custom-sorting.
        int tt_min = MAX_TIME; // it cannot take longer than this
        int tt_ind = -1;
        for (int tt = 0; tt < total_times; ++tt) {
            if (t[tt] < tt_min) {
                tt_min = t[tt];
                tt_ind = tt;
            }
        }


        // check what is going on at this time
        int mm = moonnow[tt_ind];
        int ss = shark[tt_ind];

        // We will not use this time intersection again
        t[tt_ind] = MAX_TIME;
        times_counter--;

        if (time_active_m[mm] < tt_min || time_active_s[ss] < tt_min)
            continue;

        int dx = x_m[mm] - x_s[ss];
        int dy = y_s[ss] - y_m[mm];
        // both arrived together, so we can skip this
        // if (dx == dy) ;
        // shark is blocking moonnow
        if (dx < dy)
            time_active_m[mm] = min(dy, time_active_m[mm]);
        // moonnow is blocking shark
        if (dy < dx)
            time_active_s[ss] = min(dx, time_active_s[ss]);

    }


    int ans = 0;
    for (int i = 0; i < M; ++i) {
        if (time_active_m[i] == MAX_TIME) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}

/*
SAMPLE INPUT:
10 3 3
3 1
6 4
7 1
1 2
4 3
1 8


SAMPLE OUTPUT:
2

 */