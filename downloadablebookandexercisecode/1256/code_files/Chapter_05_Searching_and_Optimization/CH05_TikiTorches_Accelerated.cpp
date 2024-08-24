#include <iostream>

using namespace std;


int main() {

    int N = 6;
    int tiki_location[6] = {1, 8, 10, 16, 20, 23}; // answer : 20
    // a few more test cases
    //int tiki_location[6] = {1, 7, 8, 9, 19, 30}; // answer (one of): 7, 8
    //int tiki_location[6] = {1, 2, 3, 7, 15, 23}; // answer (one of): 2,3
    //int tiki_location[6] = {1, 8, 10, 16, 20, 24}; // Answer : 10
    //int tiki_location[6] = {1, 10, 19, 28, 37, 46}; // Answer (one of) : 10, 19, 28, 37


    // Remove one tiki at a time, and just check the distance it creates
    // around the removed tiki.
    int max_dist = INT_MAX;
    int ans = 0;
    for (int tiki_removed = 1; tiki_removed < N - 1; ++tiki_removed) {
        int dist;

        dist = tiki_location[tiki_removed + 1] - tiki_location[tiki_removed - 1];
        if (dist < max_dist) {
            max_dist = dist;
            ans = tiki_location[tiki_removed];
        }
    }

    cout << ans << endl;

    return 0;
}
