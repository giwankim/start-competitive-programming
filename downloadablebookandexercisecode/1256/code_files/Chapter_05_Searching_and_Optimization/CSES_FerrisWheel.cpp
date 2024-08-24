#include <iostream>
#include <algorithm>

using namespace std;

int main() {


    int n, x;
    cin >> n >> x;

    int w[n];
    for (int i = 0; i < n; ++i)
        cin >> w[i];

    sort(w, w + n);

    int i1 = 0;
    int i2 = n - 1;
    int cnt = 0;

    while (i1 <= i2) {
        if (w[i1] + w[i2] <= x)
            i1++;   // We are sitting the lighter person in there as well.
        // at any rate, the heavy weight will sit there for sure
        i2--;
        cnt++;
    }

    cout << cnt;
    return 0;
}
