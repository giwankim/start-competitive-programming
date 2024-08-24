#include <iostream>

using namespace std;

// Recursion solution

int A[102][102];

void floodfill(int r, int c) {
    if (r < 0 || c < 0 || r > 101 || c > 101) return;
    if (A[r][c] != 0) return;
    A[r][c] = 2;
    floodfill(r - 1, c);
    floodfill(r + 1, c);
    floodfill(r, c - 1);
    floodfill(r, c + 1);
}

int main() {

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    int N;
    cin >> N;

    for (int r = 0; r < 102; ++r)
        for (int c = 0; c < 102; ++c)
            A[r][c] = 0;

    for (int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        A[r][c] = 1;
    }
    // A is : 0 - don't know yet. 1 - hey bale  2 - background
    floodfill(0, 0);
/*
    for (int r=1; r<=10; ++r){
        cout << endl;
        for(int c=1; c<=10; ++c){
            cout << A[r][c];
        }
    }

*/
    int ans = 0;
    for (int r = 1; r <= 100; ++r) {
        for (int c = 1; c <= 100; ++c) {
            if (A[r][c] == 1) {
                if (A[r - 1][c] == 2) ans++;
                if (A[r + 1][c] == 2) ans++;
                if (A[r][c - 1] == 2) ans++;
                if (A[r][c + 1] == 2) ans++;

            }
        }
    }

    cout << ans;
    return 0;
}
