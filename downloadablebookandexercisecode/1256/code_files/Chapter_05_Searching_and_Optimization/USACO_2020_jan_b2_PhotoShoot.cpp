// http://usaco.org/index.php?page=viewproblem2&cpid=988
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);

    int N;
    cin >> N;

    int b[N - 1];
    for (int i = 0; i < N - 1; ++i)
        cin >> b[i];

    int a[N];
    //search
    for (int a0 = 1; a0 < b[0]; ++a0) {
        a[0] = a0;
        for (int i = 1; i < N; ++i)
            a[i] = b[i - 1] - a[i - 1];

        // check
        int as[N];
        copy(a, a + N, as);
        sort(as, as + N);
        bool works = true;
        for (int i = 0; i < N; ++i)
            if (as[i] != i + 1) {
                works = false;
                break;
            }
        if (works) break;
    }

    for (int i = 0; i < N; ++i) {
        cout << a[i];
        if (i < N - 1) cout << " ";
    }

    return 0;
}
