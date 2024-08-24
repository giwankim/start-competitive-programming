#include <iostream>

using namespace std;

int main() {


    int N = 7;
    int shell_value[] = {1, 2, 3, 5, 1, 4, 2};

    int photo_value = 0;
    int answer;
    for (int group_len = 1; group_len <= N; ++group_len) {
        photo_value += shell_value[group_len - 1];
        int index = 0;
        int sum = 0;
        while (index < N) {
            sum += shell_value[index];
            if (sum == photo_value) sum = 0;
            if (sum > photo_value) break;
            index++;
        }
        if (index == N && sum == 0) {
            answer = photo_value;
            break;
        }
    }

    cout << answer;

    return 0;
}
