/*
Example 1:
8
()((()))

Answer: Yes

Example 2:
8
()())(()

Answer: No

 */

#include <iostream>
#include <string>
using namespace std;

int main() {

    int N;
    cin >> N;
    string str;
    cin >> str;

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (str[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) break;
    }

    string ans;
    if (cnt == 0) ans = "Yes";
    else ans = "No";
    cout << ans << "\n";
}
