#include <iostream>

using namespace std;

int main() {

    int a = 70, y_0 = 20, b = 65, c = 90, y_1 = 50;

    int dist = 100 - y_0;
    if (a > b && a < c && y_0 < y_1) {

        int d_left = 2 * (a - b);
        int d_right = 2 * (c - a);

        dist += min(d_left, d_right);

    }

    cout << dist;

    return 0;
}
