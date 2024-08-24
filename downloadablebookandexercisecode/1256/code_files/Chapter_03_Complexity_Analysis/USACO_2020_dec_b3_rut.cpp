#include <iostream>

#include <vector>
#include <math.h>

using namespace std;

#define MAX_TIME  1000000001

int main() {

    int N;
    cin >> N;

    char dir[N];
    int x[N], y[N];
    int time_active[N];
    for (int i = 0; i < N; ++i) {
        cin >> dir[i] >> x[i] >> y[i];
        time_active[i] = MAX_TIME;
    }

    // find all possible interaction times
    // Keep in mind: Some of these will not happen
    // We can use arrays of size N^2. N is small enough. But vectors are easier, so I used this.
    vector<int> t, cowE, cowN; // time, cowE, cowN for the interactions
    for (int e = 0; e < N; ++e) {
        if (dir[e] == 'N') continue;
        for (int n = 0; n < N; ++n) {
            if (dir[n] == 'E') continue;

            if (x[e] <= x[n] && y[n] <= y[e]) {
                int dt = min(x[n] - x[e], y[e] - y[n]);
                t.push_back(dt);
                cowE.push_back(e);
                cowN.push_back(n);
            }
        }
    }

    // Now, progress every time up to the next important point, and check what is going there.
    while (!t.empty()) {

        // Find the next time instance. We could have used sort before, but wanted to avoid this here.
        // See python for easy custom-sorting.
        int tt_min = MAX_TIME;
        int tt_ind = -1;
        for (int tt = 0; tt < t.size(); ++tt) {
            if (t[tt] < tt_min) {
                tt_min = t[tt];
                tt_ind = tt;
            }
        }


        // check what is going on at this time
        int e = cowE[tt_ind];
        int n = cowN[tt_ind];

        // We will not this time intersection again
        t.erase(t.begin() + tt_ind);
        cowE.erase(cowE.begin() + tt_ind);
        cowN.erase(cowN.begin() + tt_ind);

        if (tt_min > time_active[n] || tt_min > time_active[e])
            continue;

        int dx = x[n] - x[e];
        int dy = y[e] - y[n];
        // both arrived together, so we can skip this
        // if (dx == dy) ;
        // e is blocking n
        if (dx < dy)
            time_active[n] = min(dy, time_active[n]);
        // n is blocking e
        if (dy < dx)
            time_active[e] = min(dx, time_active[e]);

    }


    for (int i = 0; i < N; ++i) {
        if (time_active[i] == MAX_TIME) cout << "Infinity";
        else cout << time_active[i];

        cout << endl;
    }


    return 0;
}

