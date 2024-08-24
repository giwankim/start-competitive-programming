#include <iostream>

using namespace std;

int main() {

    // Sample input
    int N = 5;
    int W = 10;
    int weight[] = {2, 4, 5, 7, 9};


    int answer = 0;
    int top_cow = N - 1;
    int bot_cow = 0;
    while (top_cow >= bot_cow) {
        answer++;
        int cow1 = weight[top_cow];
        top_cow--;
        if (cow1 + weight[bot_cow] <= W)
            bot_cow++;
    }

    cout << answer;

    return 0;
}
