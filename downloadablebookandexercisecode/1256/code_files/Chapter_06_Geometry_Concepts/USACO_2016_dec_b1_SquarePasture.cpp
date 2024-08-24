#include <iostream>

using namespace std;

int main() {

    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    // rec1
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // rec2
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int area = 0;

    // Your code here

    int xbl = min(x1, x3);
    int ybl = min(y1, y3);
    int xtr = max(x2, x4);
    int ytr = max(y2, y4);

    int d = max(xtr - xbl, ytr - ybl);
    area = d * d;

    cout << area;


    return 0;
}
