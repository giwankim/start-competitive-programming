// https://cses.fi/problemset/task/1083

#include <iostream>

using namespace std;

int main() {
    long n; // b/c the n*(n+1) can overflow
    cin >> n;

    long sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        int a;
        cin >> a;
        sum += a;
    }

    int missing_a = (n + 1) * n / 2 - sum;
    cout << missing_a << endl;
    return 0;
}
