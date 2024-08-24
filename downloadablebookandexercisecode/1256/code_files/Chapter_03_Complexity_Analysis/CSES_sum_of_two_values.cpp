// https://cses.fi/problemset/task/1640

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    long long a[n]; // need to use long long
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long b[n];
    copy(a, a + n, b);

    sort(a, a + n);
    int i0 = 0;
    int i1 = n - 1;
    bool found = false;
    while (i0 < i1) {
        if (a[i0] + a[i1] > x) {
            i1--;
            continue;
        }
        if (a[i0] + a[i1] == x) {
            found = true;
            break;
        }
        if (a[i0] + a[i1] < x) {
            i0++;
            continue;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE";
        exit(0);
    }

    int val1 = a[i0], id1 = -1;
    int val2 = a[i1], id2 = -1;
    for (int i = 0; i < n; ++i) {
        if (id1 == -1 && b[i] == val1) id1 = i;
        if (id2 == -1 && id1 != i && b[i] == val2) id2 = i;
    }
    cout << id1 + 1 << " " << id2 + 1;
    
}
