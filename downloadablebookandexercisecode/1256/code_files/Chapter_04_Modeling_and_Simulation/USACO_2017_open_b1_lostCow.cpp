#include <iostream>

using namespace std;

int main() {

    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin >> x >> y;


    //method 2: Every time we go 'out and back' (unless we found her)

    int l = 0;
    bool found = x == y;
    int step = 1;
    int dx = 1; // direction
    while (!found) {

        if ((dx > 0 && x <= y && y <= x + step) || (dx < 0 && x - step <= y && y <= x)) {
            found = true;
            l += abs(y - x);
        } else {
            l += 2 * step;
            step *= 2;
            dx *= -1;
        }
    }


    //method 1: How much we did every time
/*
    int l = 0;
    bool found = x==y;
    int step = 1;
    int dx = 1; // direction
    int xp = x;
    while (!found){

        if ( (dx>0 && x<=y && y<=x+step)  ||  (dx<0 && x-step<=y && y<=x) ) {
            found = true;
            l += abs(y-xp);
        }
        else {
            l += abs(x+dx*step - xp);
            xp = x+dx*step;
            step *= 2;
            dx *= -1;
        }
    }
  */

    cout << l;

    return 0;
}
