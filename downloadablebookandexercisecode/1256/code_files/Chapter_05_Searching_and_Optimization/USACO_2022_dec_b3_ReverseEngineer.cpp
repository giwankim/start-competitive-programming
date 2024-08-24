#include <iostream>

using namespace std;

int main() {

    int T;
    cin >> T;

    for (int t=0; t<T; ++t) {
        int N;
        int M;

        cin >> N >> M;

        string a[M];
        int res[M];
        bool need_to_check[M];
        for (int r = 0; r < M; ++r) {
            cin >> a[r];
            cin >> res[r];
            need_to_check[r] = true;
        }
        bool lie = false;

        for (int c1 = 0; c1 < N; ++c1) {
            for (int c = 0; c < N; ++c) {
                char zero_is = ' ';
                char one_is = ' ';
                int zero_decides = true;
                int one_decides = true;
                for (int r = 0; r < M; ++r) {
                    if (!need_to_check[r]) continue;
                    if (a[r][c] == '0') {
                        if (zero_is == ' ') zero_is = res[r];
                        if (zero_is != res[r]) zero_decides = false;
                    }
                    if (a[r][c] == '1') {
                        if (one_is == ' ') one_is = res[r];
                        if (one_is != res[r]) one_decides = false;
                    }
                }
                for (int r = 0; r < M; ++r) {
                    if (zero_decides && a[r][c] == '0') need_to_check[r] = false;
                    if (one_decides && a[r][c] == '1') need_to_check[r] = false;
                }
            }
        }
        int val = -1;
        for (int r = 0; r < M; ++r) {
            if (!need_to_check[r]) continue;
            if (val == -1) val = res[r];
            if (val != res[r]) lie = true;
        }


        string out = (lie)? "LIE" : "OK";
        cout << out << endl;
    }

    return 0;
}
