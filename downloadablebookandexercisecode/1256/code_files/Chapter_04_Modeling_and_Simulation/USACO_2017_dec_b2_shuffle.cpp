#include <iostream>

using namespace std;

int main() {

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int N;
    cin >> N;

    int a[N + 1];
    for (int i = 1; i <= N; ++i)
        cin >> a[i];

    int ID[N + 1];
    for (int i = 1; i <= N; ++i)
        cin >> ID[i];

    int *cows = new int[N + 1];
    int *cows_next = new int[N + 1];
    for (int i = 1; i <= N; ++i)
        cows[i] = i;

    for (int j = 0; j < 3; ++j) {
        for (int i = 1; i <= N; ++i)
            cows_next[a[i]] = cows[i];
        int *tmp = cows;
        cows = cows_next;
        cows_next = tmp;
    }

    int ans[N + 1];
    for (int i = 1; i <= N; ++i) {
        ans[cows[i]] = ID[i];
    }

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << endl;

    return 0;
}
