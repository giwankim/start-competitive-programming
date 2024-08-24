#include <iostream>

using namespace std;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int dist = 0;
    dist = abs(a - b);

    dist = min(dist, abs(x - a) + abs(y - b));
    dist = min(dist, abs(x - b) + abs(y - a));

    cout << dist << endl;

}