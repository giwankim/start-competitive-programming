// http://usaco.org/index.php?page=viewproblem2&cpid=1299

#include <iostream>

using namespace std;

int main() {

    long long T;
    int N;

    cin >> N >> T;

    long long t = 1;
    long long ans = 0;

    for (int i = 0; i < N; ++i) {
        long long d;
        long long b;
        cin >> d >> b;

        if (t <= d) t = d;
        if (T - t + 1 < b) b = T - t + 1;

        ans += b;
        t += b ;
        if (t == T) break;

    }

    cout << ans << "\n";

}
