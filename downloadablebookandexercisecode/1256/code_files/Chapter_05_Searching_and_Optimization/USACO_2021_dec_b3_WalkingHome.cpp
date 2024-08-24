#include <iostream>

using namespace std;

int main() {

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, K;
        cin >> N >> K;

        int A[N][N];
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                char ch;
                cin >> ch;
                A[r][c] = (ch == '.') ? 0 : 1;
            }
        }

        int out = 0;

        bool hay;
        if (K >= 1) {
            // right and down
            hay = false;
            for (int c = 0; c < N; ++c)
                if (A[0][c] == 1) hay = true;
            for (int r = 0; r < N; ++r)
                if (A[r][N - 1] == 1) hay = true;
            if (!hay) out++;

            // down and right
            hay = false;
            for (int r = 0; r < N; ++r)
                if (A[r][0] == 1) hay = true;
            for (int c = 0; c < N; ++c)
                if (A[N - 1][c] == 1) hay = true;
            if (!hay) out++;
        }

        if (K >= 2) {
            // right and down and right
            for (int c_turn = 1; c_turn < N - 1; ++c_turn) {
                hay = false;
                for (int c = 0; c <= c_turn; ++c)
                    if (A[0][c] == 1) hay = true;
                for (int r = 0; r < N; ++r)
                    if (A[r][c_turn] == 1) hay = true;
                for (int c = c_turn; c < N; ++c)
                    if (A[N - 1][c] == 1) hay = true;
                if (!hay) out++;
            }

            // down and right and down
            for (int r_turn = 1; r_turn < N - 1; ++r_turn) {
                hay = false;
                for (int r = 0; r <= r_turn; ++r)
                    if (A[r][0] == 1) hay = true;
                for (int c = 0; c < N; ++c)
                    if (A[r_turn][c] == 1) hay = true;
                for (int r = r_turn; r < N; ++r)
                    if (A[r][N - 1] == 1) hay = true;
                if (!hay) out++;
            }
        }
        if (K >= 3) {

            for (int c_turn = 1; c_turn < N - 1; ++c_turn) {
                for (int r_turn = 1; r_turn < N - 1; ++r_turn) {

                    // right and down and right and down
                    hay = false;
                    for (int c = 0; c <= c_turn; ++c)
                        if (A[0][c] == 1) hay = true;
                    for (int r = 0; r <= r_turn; ++r)
                        if (A[r][c_turn] == 1) hay = true;
                    for (int c = c_turn; c < N; ++c)
                        if (A[r_turn][c] == 1) hay = true;
                    for (int r = r_turn; r < N; ++r)
                        if (A[r][N - 1] == 1) hay = true;
                    if (!hay) out++;


                    // down and right and down and right
                    hay = false;
                    for (int r = 0; r <= r_turn; ++r)
                        if (A[r][0] == 1) hay = true;
                    for (int c = 0; c <= c_turn; ++c)
                        if (A[r_turn][c] == 1) hay = true;
                    for (int r = r_turn; r < N; ++r)
                        if (A[r][c_turn] == 1) hay = true;
                    for (int c = c_turn; c < N; ++c)
                        if (A[N - 1][c] == 1) hay = true;
                    if (!hay) out++;
                }
            }
        }

        cout << out << endl;
    }

    return 0;
}