#include <iostream>

using namespace std;

int main() {

    int a = 20, b = 70, c = 10, d = 85;
    int dist1 = abs(a - b);
    int dist2 = abs(c - a) + abs(d - b);
    int dist3 = abs(d - a) + abs(c - b);
    int ans = min(min(dist1, dist2), dist3);

    cout << ans;

    return 0;
}
