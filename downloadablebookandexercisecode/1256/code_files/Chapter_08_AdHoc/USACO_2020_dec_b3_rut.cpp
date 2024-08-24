// http://www.usaco.org/index.php?page=viewproblem2&cpid=1061
#include <iostream>

#include <vector>
#include <math.h>

using namespace std;

#define MAX_AMT  1000000001

int main() {

    int N;
    cin >> N;

    char dir[N];
    int x[N], y[N];
    int amt[N];
    for (int i = 0; i < N; ++i) {
        cin >> dir[i] >> x[i] >> y[i];
        amt[i] = MAX_AMT;
    }

    // find all possible interaction times
    // Keep in mind: Some of these will not happen
    vector<int> t, a, b; // time, cow1, cow2 for the interactions
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int e, n; // which one is 'E' and which is 'N'
            if (dir[i] == dir[j]) continue;
            if (dir[i] == 'E') {
                e = i;
                n = j;
            } else {
                e = j;
                n = i;
            }
            if (x[e] <= x[n] && y[n] <= y[e]) {
                int dt = max(x[n] - x[e], y[e] - y[n]); // when the second one reaches there
                t.push_back(dt);
                a.push_back(e);
                b.push_back(n);
            }
        }
    }

    // Now, progress every time up to the next important point, and check what is going there.
    while (!t.empty()) {
        int tt_min = MAX_AMT;
        int tt_ind = -1;
        for (int tt = 0; tt < t.size(); ++tt) {
            if (t[tt] < tt_min) {
                tt_min = t[tt];
                tt_ind = tt;
            }
        }

        // check what is going on in this case
        int e = a[tt_ind];
        int n = b[tt_ind];
        // both arrived together, so we can skip this
        if ((x[n] - x[e]) == (y[e] - y[n])) {
            t.erase(t.begin() + tt_ind);
            a.erase(a.begin() + tt_ind);
            b.erase(b.begin() + tt_ind);
            continue;
        }
        // e is blocking n
        if ((x[n] - x[e]) < (y[e] - y[n])) {
            if (amt[n] == MAX_AMT &&
                amt[e] + x[e] >= x[n]) { // // Check n is not already done, and that e was not blocked before
                amt[n] = y[e] - y[n];
            }

            t.erase(t.begin() + tt_ind);
            a.erase(a.begin() + tt_ind);
            b.erase(b.begin() + tt_ind);
            continue;
        }
        // n is blocking e
        if ((x[n] - x[e]) > (y[e] - y[n])) {
            if (amt[e] == MAX_AMT &&
                amt[n] + y[n] >= y[e]) { // Check e is not already done, and that n was not blocked before
                amt[e] = x[n] - x[e];
            }
            t.erase(t.begin() + tt_ind);
            a.erase(a.begin() + tt_ind);
            b.erase(b.begin() + tt_ind);
            continue;
        }
    }


    for (int i = 0; i < N; ++i) {
        if (amt[i] == MAX_AMT) cout << "Infinity";
        else cout << amt[i];

        cout << endl;
    }


    return 0;
}