#include <iostream>
#include <climits>

using namespace std;

// N is capped at 100, each direction is kept at 10 ==> Maximum 1000. We want to put him in the middle.
#define field_size  2001
int field[field_size][field_size];

int main() {

    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int N;
    cin >> N;


    int fx = 1000;
    int fy = 1000;
    int t = 0; // time

    for (int i = 0; i < field_size; ++i) {
        for (int j = 0; j < field_size; ++j) {
            field[i][j] = -1;
        }
    }

    int minX = INT_MAX;
    for (int i = 0; i < N; ++i) {
        // For each line
        char dir;
        int steps;
        cin >> dir >> steps;

        int dx = 0, dy = 0;

        switch (dir) {
            case 'N':
                dy = 1;
                break;
            case 'S':
                dy = -1;
                break;
            case 'E':
                dx = 1;
                break;
            case 'W':
                dx = -1;
                break;
        }

        for (int j = 0; j < steps; ++j) {
            fx += dx;
            fy += dy;
            t++;
            if ((field[fx][fy] != -1) && (t - field[fx][fy]) < minX)
                minX = t - field[fx][fy];
            field[fx][fy] = t;
        }
    }
    if (minX == INT_MAX) minX = -1;
    cout << minX;

    return 0;
}
