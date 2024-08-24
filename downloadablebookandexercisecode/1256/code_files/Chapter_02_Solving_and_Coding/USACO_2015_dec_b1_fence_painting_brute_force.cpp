// http://usaco.org/index.php?page=viewproblem2&cpid=567

#include <iostream>

using namespace std;

int main() {

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;

    int l = 0;

    // just check every unit of the fence

    for (double i = 0.5; i < 100; ++i ) {
        if ( ( i > a && i < b ) || ( i > c && i < d ) ) {
            l++;
        }
    }

    cout << l;

}
