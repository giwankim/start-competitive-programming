#include <iostream>

using namespace std;

// we can solve much simpler with 'set' data structure.
// we will not use this for Bronze
// we will do brute force

int main() {

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N;
    cin >> N;

    string str;
    cin >> str;

    int len = 1;

    for (len = 1; len < N; len++) {
        bool no_duplicate = true;
        for (int i = 0; i <= N - len && no_duplicate; ++i) {
            string s1 = str.substr(i, len);
            for (int j = 0; j < i && no_duplicate; ++j) {
                if (s1 == str.substr(j, len)) no_duplicate = false;
            }

        }
        if (no_duplicate) break;
    }

    cout << len;
    return 0;
}