#include <iostream>

using namespace std;

int main() {

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x11, y11, x21, y21;
    cin >> x11 >> y11 >> x21 >> y21;

    int x12, y12, x22, y22;
    cin >> x12 >> y12 >> x22 >> y22;

    int x1t, y1t, x2t, y2t;
    cin >> x1t >> y1t >> x2t >> y2t;

    int area = 0;


    int a11 = (x21 - x11) * (y21 - y11);
    int a22 = (x22 - x12) * (y22 - y12);

    double a11tt = max(0, min(x21, x2t) - max(x11, x1t)) * max(0, min(y21, y2t) - max(y11, y1t));
    double a22tt = max(0, min(x22, x2t) - max(x12, x1t)) * max(0, min(y22, y2t) - max(y12, y1t));
    area = (int) (a11 + a22 - a11tt - a22tt);


    // End of your code

    cout << area;


    return 0;
}
