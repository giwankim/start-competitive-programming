#include <iostream>

using namespace std;

int main() {

    int N = 3;
    int seats[3] = {90, 3, 4};

    int min_total_dist = N * 100;
    int min_entry_seat = 0;
    for (int entry_seat = 1; entry_seat <= 100; ++entry_seat) {
        int total_dist = 0;
        for (int cow = 0; cow < N; ++cow) {
            int cow_seat = seats[cow];
            int dist_CW, dist_CCW;
            if (cow_seat >= entry_seat) {
                dist_CW = cow_seat - entry_seat;
                dist_CCW = 100 - dist_CW;
            } else {
                dist_CCW = entry_seat - cow_seat;
                dist_CW = 100 - dist_CCW;
            }
            total_dist += min(dist_CW, dist_CCW);
        }
        if (total_dist < min_total_dist) {
            min_total_dist = total_dist;
            min_entry_seat = entry_seat;
        }
    }

    cout << min_entry_seat;

    return 0;
}
