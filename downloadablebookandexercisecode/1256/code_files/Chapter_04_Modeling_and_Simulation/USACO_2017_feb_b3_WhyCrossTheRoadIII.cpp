#include <iostream>
#include <climits>

using namespace std;

int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int N;
    cin >> N;

    int arrival[N];
    int answering[N];
    int processed[N];

    for (int i = 0; i < N; ++i) {
        cin >> arrival[i] >> answering[i];
        processed[i] = 0;
    }

    // We know at the end we will process N cows, one at a time
    int current_time = 0;
    for (int i = 0; i < N; ++i) {
        // find the next one to be processed
        int mint = INT_MAX;
        int to_process = -1;
        for (int j = 0; j < N; ++j) {
            if (!processed[j] && arrival[j] < mint) {
                to_process = j;
                mint = arrival[j];
            }
        }
        // process this one
        processed[to_process] = 1;
        current_time = max(current_time, arrival[to_process]) + answering[to_process];
    }

    cout << current_time;

    return 0;
}