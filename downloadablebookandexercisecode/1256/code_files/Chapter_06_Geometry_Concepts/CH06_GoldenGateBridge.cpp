#include <iostream>

using namespace std;

int main() {

    int N = 100, a = 10, b = 50, c = 40, d = 80;

    int units_covered = 0;

    // Brute force
    /*
    for (float x = 0.5; x < N; ++x) {
        if ((x >= a && x <= b) ||
            (x >= c && x <= d)) {
            units_covered++;
        }
    }
    cout << units_covered;
    /**/

    // Casework
    /*
    if (b <= c) units_covered = (b - a) + (c - d);  // case 1
    if (d <= a) units_covered = (b - a) + (c - d);  // case 2
    if (a <= c && c <= b && b <= d) units_covered = (d - a);  // case 3
    if (c <= a && a <= d && d <= b) units_covered = (b - c);  // case 4
    if (a <= c && b >= d) units_covered = (b - a);  // case 5
    if (c <= a && d >= b) units_covered = (d - c);  // case 6

    cout << units_covered;
    /**/

    // Geometric analysis

    int left_edge_of_overlap = max(a, c);
    int right_edge_of_overlap = min(b, d);
    int length_of_overlap = right_edge_of_overlap - left_edge_of_overlap;
    length_of_overlap = max(0, length_of_overlap);

    units_covered = (b - a) + (d - c) - length_of_overlap;
    cout << units_covered;


    return 0;
}
