#include <iostream>
#include <climits>

using namespace std;


int main() {

    int N = 6;
    int tiki_location[6] = {1, 8, 10, 16, 20, 23}; // answer : 20
    // a few more test cases
    // int tiki_location[6] = {1, 7, 8, 9, 19, 30}; // answer : 7
    //int tiki_location[6] = {1, 2, 3, 7, 15, 23}; // answer : 2

    int min_max_distance = INT_MAX;
    int min_max_location;

    for (int tiki_removed = 1; tiki_removed < N - 1; ++tiki_removed) {
        int max_dist = 0;
        int dist = 0;

        for (int i = 1; i < N; ++i) {
            if (i == tiki_removed) continue;
            if (i == tiki_removed + 1) {
                dist = tiki_location[i] - tiki_location[i - 2];
            } else {
                dist = tiki_location[i] - tiki_location[i - 1];
            }
            max_dist = max(max_dist, dist);
        }

        if (max_dist < min_max_distance) {
            min_max_distance = max_dist;
            min_max_location = tiki_removed;
        }
    }

    cout << tiki_location[min_max_location] << endl;

    return 0;
}
