// http://usaco.org/index.php?page=viewproblem2&cpid=915

#include <iostream>

using namespace std;

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    int ans_min = 0;
    int ans_max = 0;

    // arrange a,b,c in order
    // poor men's bubble sort. pushing the smallest to a

    int tmp;    // We can use swap(arg1, arg2) instead
    if (c < b) {
        tmp = b;
        b = c;
        c = tmp;
    }
    if (b < a) {
        tmp = a;
        a = b;
        b = tmp;
    }  // by here a is smallest
    if (c < b) {
        tmp = b;
        b = c;
        c = tmp;
    }

    // Algorithm
    ans_min = 2; // we can always do it in 2
    if (c - a == 2) {
        ans_min = 0;
    } else {
        if (c - b == 2 || b - a == 2) {
            ans_min = 1;
        } else {
            ans_min = 2;
        }
    }

    ans_max = max(c - b - 1, b - a - 1);

    cout << ans_min << endl << ans_max << endl;

}
