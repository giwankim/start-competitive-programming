#include <iostream>
#include <math.h>

using namespace std;

void into_digits(int X, int *x) {
    x[0] = X % 10;
    x[1] = (X / 10) % 10;
    x[2] = (X / 100);
}

void solve_quad(long c, long b, long a, int *sols) {

    sols[0] = 0;
    sols[1] = 0;
    double delta = b * b - 4 * a * c;
    if (delta < 0) return;
    double f = sqrt(delta);
    long round_f = round(f);
    if (round_f * round_f != delta) return;

    int y1 = -b + round_f;
    if (y1 % (2 * a) == 0) sols[0] = y1 / (2 * a);
    int y2 = -b - round_f;
    if (y2 % (2 * a) == 0) sols[1] = y2 / (2 * a);

    if (sols[0] < 10) sols[0] = 0;
    if (sols[1] < 10) sols[1] = 0;

    return;
}


int main() {

    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w", stdout);


    int K;
    cin >> K;

    for (int k = 0; k < K; ++k) {
        int X, Y;
        cin >> X >> Y;

        int x3[3], y3[3];
        into_digits(X, x3);
        into_digits(Y, y3);

        for (long bx = 10; bx < 15001; bx++) {
            long valx = x3[0] + bx * x3[1] + bx * bx * x3[2];
            int sols[2];
            solve_quad(y3[0] - valx, y3[1], y3[2], sols);
            int by = sols[0];
            long valy = y3[0] + by * y3[1] + by * by * y3[2];
            if (valy == valx) {
                cout << bx << " " << by << endl;
                break;
            }
            by = sols[1];
            valy = y3[0] + by * y3[1] + by * by * y3[2];
            if (valy == valx) {
                cout << bx << " " << by << endl;
                break;
            }
        }

    }

    return 0;
}
