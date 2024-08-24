#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    string s[N];
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    int ans = 0;

    for (int i = 0; i < N; ++i) {
        string s0 = s[i].substr(0, s[i].length() - 1);
        bool found = false;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            string s1 = s[j].substr(0, s0.length()); // it's okay if not enough elements in s[j]
            if (s0 == s1) {
                found = true;
                break;
            }
        }
        if (!found) ans++;
    }

    cout << ans;
}

/*
Sample Input
5
121S
1211S
1212S
1S
2121S
Sample Output
3
*/
