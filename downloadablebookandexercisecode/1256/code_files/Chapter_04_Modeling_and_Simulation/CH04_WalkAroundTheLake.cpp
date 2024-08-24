#include <iostream>

using namespace std;

int main() {

    // Sample input
    int D = 30;
    int N = 5;
    int bessie_covers_in_minute[] = {8, 14, 19, 16, 6};
    int friend_covers_in_minute[] = {6, 5, 6, 5, 6};

    int answer;
    int dist_bessie = 0;
    int dist_friend = D;
    int t = 0;
    while (t < N && dist_bessie < dist_friend) {
        dist_bessie += bessie_covers_in_minute[t];
        dist_friend += friend_covers_in_minute[t];
        t++;
    }
    if (dist_bessie >= dist_friend)
        answer = t;
    else
        answer = -1;

    cout << answer << endl;

    return 0;
}
