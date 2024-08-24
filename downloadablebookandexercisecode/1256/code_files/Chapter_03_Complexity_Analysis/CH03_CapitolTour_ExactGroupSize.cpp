#include <iostream>

using namespace std;

int main() {
    int N = 4;
    int K = 20;
    int line1[] = {4, 7, 12, 15};
    int line2[] = {6, 8, 14, 17};


    cout << "Method 1: O(N^2)\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int sum = line1[i] + line2[j];
            if (sum == K) {
                cout << line1[i] << " " << line2[j] << '\n';
                return 0;  // Uncomment to use Method 1
            }
        }
    }

    cout << "Method 2: O(N)\n";
    int i = 0;
    int j = N - 1;

    while (i < N && j >= 0) {
        int sum = line1[i] + line2[j];
        if (sum == K) {
            cout << line1[i] << " " << line2[j] << '\n';
            return 0;
        }
        if (sum > K) j--;
        if (sum < K) i++;
    }

}
