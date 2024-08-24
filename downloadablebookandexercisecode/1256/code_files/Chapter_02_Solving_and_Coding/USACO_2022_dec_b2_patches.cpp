// http://www.usaco.org/index.php?page=viewproblem2&cpid=1252

#include <iostream>

using namespace std;

int main() {

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, K;
        cin >> N >> K;
        string str;
        cin >> str;

        string out(N, '.');
        int cnt = 0;

        // way 2
        int g_last_covered = -1;
        int h_last_covered = -1;
        for (int i = 0; i < N; ++i) {
            char cow;
            cow = str[i];
            if (cow == 'G') {
                if (g_last_covered >= i) continue;
                cnt++;
                int new_loc = i + K;
                new_loc = min(new_loc, N - 1);
                //if (out[new_loc] != '.') new_loc=max(0,N-2);
                out[new_loc] = 'G';
                g_last_covered = i + 2 * K;
            }
            if (cow == 'H') {
                if (h_last_covered >= i) continue;
                cnt++;
                int new_loc = i + K;
                new_loc = min(new_loc, N - 1);
                //if (out[new_loc] != '.') new_loc=max(0,N-2);
                out[new_loc] = 'H';
                h_last_covered = i + 2 * K;
            }

        }





        // way 1
        /*
        int g_covered=0;
        int h_covered=0;
        char cow;
        for (int i=0; i<N; ++i){
            cow = str[i];
            g_covered = max(0,g_covered-1);
            h_covered = max(0,h_covered-1);
            if (cow=='G') {
                if (g_covered > 0) continue;
                cnt++;
                int new_loc = i+K;
                new_loc=min(new_loc,N-1);
                if (out[new_loc] != '.') new_loc=max(0,N-2);
                out[new_loc]='G';
                g_covered = 2*K+1;
            }
            if (cow=='H') {
                if (h_covered > 0) continue;
                cnt++;
                int new_loc = i+K;
                new_loc=min(new_loc,N-1);
                if (out[new_loc] != '.') new_loc=max(0,N-2);
                out[new_loc]='H';
                h_covered = 2*K+1;
            }

        }

        */
        cout << cnt << endl;
        cout << out << endl;
    }

}
