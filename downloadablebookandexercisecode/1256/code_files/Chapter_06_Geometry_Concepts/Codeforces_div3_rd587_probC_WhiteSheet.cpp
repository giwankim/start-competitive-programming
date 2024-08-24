// https://codeforces.com/contest/1216/problem/C
#include <iostream>

using namespace std;


int main() {

    /*******************
    * read input
    ********************/
    int x1, x2, x3, x4, x5, x6, y1, y2, y3, y4, y5, y6;
    //long long x1,x2,x3,x4,x5,x6,y1,y2,y3,y4,y5,y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

    // White
    // w_bl = {x1, y1};
    // w_tr = {x2, y2};


    // Black-1
    // b1_bl = {x3, y3};
    // b1_tr = {x4, y4};

    // Black-2
    // b2_bl = {x5, y5};
    // b2_tr = {x6, y6};

    // Calculate sq(w) =? (intersect(w,b1) + intersect (w,b2) - overlap (w,b1,b2))

    // intersect(w,b1)
    long long xl = max(x1, x3);
    long long xr = min(x2, x4);
    long long dx = xr - xl;

    long long yb = max(y1, y3);
    long long yt = min(y2, y4);
    long long dy = yt - yb;

    long long A_wb1 = 0;
    if (dy > 0 && dx > 0) A_wb1 = dx * dy;

    // intersect(w,b2)
    xl = max(x1, x5);
    xr = min(x2, x6);
    dx = xr - xl;

    yb = max(y1, y5);
    yt = min(y2, y6);
    dy = yt - yb;

    long long A_wb2 = 0;
    if (dy > 0 && dx > 0) A_wb2 = dx * dy;

    // intersect(w,b1,b2)
    xl = max(max(x1, x3), x5);
    xr = min(min(x2, x4), x6);
    dx = xr - xl;

    yb = max(max(y1, y3), y5);
    yt = min(min(y2, y4), y6);
    dy = yt - yb;

    long long A_wb1b2 = 0;
    if (dy > 0 && dx > 0) A_wb1b2 = dx * dy;


    // Total A_w
    long long A_w = (x2 - x1) * (y2 - y1);


    // compare
    if (A_w == (A_wb1 + A_wb2 - A_wb1b2))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}
