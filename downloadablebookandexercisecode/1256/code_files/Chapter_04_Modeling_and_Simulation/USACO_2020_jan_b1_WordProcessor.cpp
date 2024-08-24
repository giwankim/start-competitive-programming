#include <iostream>

#include <cstdio>  // from file
#include <string>

using namespace std;


int main() {
    int N, k;
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    cin >> N >> k;
    string str;
    int len = 0;
    for (int i = 0; i < N; ++i) {
        cin >> str;
        int l1 = str.length();
        if (len + l1 > k) {
            cout << "\n" << str;
            len = l1;
        } else {
            if (len > 0) cout << " ";
            len += l1;
            cout << str;
        }
    }
    return 0;
}

