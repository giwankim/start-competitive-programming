#include <iostream>

using namespace std;

int main() {
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);

    int N;
    cin >> N;

    int X[N], Y[N];

    int min_x = 40000, min_x_2 = 40000;
    int min_y = 40000, min_y_2 = 40000;

    int max_x = 0, max_x_2 = 0;
    int max_y = 0, max_y_2 = 0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        X[i] = x;
        Y[i] = y;

        if (x <= min_x) {
            min_x_2 = min_x;
            min_x = x;
        }
        else if (x < min_x_2) { min_x_2 = x; }

        if (x >= max_x) {
            max_x_2 = max_x;
            max_x = x;
        }
        else if (x > max_x_2) { max_x_2 = x; }

        if (y <= min_y) {
            min_y_2 = min_y;
            min_y = y;
        }
        else if (y < min_y_2) { min_y_2 = y; }

        if (y >= max_y) {
            max_y_2 = max_y;
            max_y = y;
        }
        else if (y > max_y_2) { max_y_2 = y; }

    }

    int area;
    area = (max_x - min_x) * (max_y - min_y);
    for (int i = 0; i < N; ++i) {
        int xbig = (X[i] == max_x) ? max_x_2 : max_x;
        int xsmall = (X[i] == min_x) ? min_x_2 : min_x;
        int ybig = (Y[i] == max_y) ? max_y_2 : max_y;
        int ysmall = (Y[i] == min_y) ? min_y_2 : min_y;

        area = min(area, (xbig - xsmall) * (ybig - ysmall));
    }

    cout << area << endl;

    return 0;
}
