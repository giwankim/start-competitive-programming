#include <iostream>

using namespace std;

int main() {

    // Sample input
    int N = 8;
    int M = 3;
    int K = 7;

    int a[] = {0, 3, 7, 2, 1, 4, 8, 5, 6};

    char cups_old[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char cups_new[N + 1];

    for (int i = 0; i < M; ++i) {
        for (int old_loc = 1; old_loc <= N; ++old_loc) {
            int new_loc = a[old_loc];
            cups_new[new_loc] = cups_old[old_loc];
        }
        copy(cups_new, cups_new + N + 1, cups_old);
    }


    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (cups_old[i] == 'G') {
            ans = i;
        }
    }


    cout << ans << endl;
    return 0;
}
