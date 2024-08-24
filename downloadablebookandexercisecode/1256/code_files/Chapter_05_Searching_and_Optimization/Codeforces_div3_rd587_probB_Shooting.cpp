//https://codeforces.com/contest/1216/problem/B

#include <iostream>
#include <climits>

using namespace std;

int main() {

    int N;
    cin >> N;

    // probably the easiest way is to do sorting with special compartor, in order to get the permutaiton of ordering as well.


    // we could use vector and then take out each one we use
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int val = 0;
    int order[N];

    for (int cnt = 1; cnt <= N; ++cnt) {
        int max_val = -1;
        int loc = 0;
        for (int i = 0; i < N; ++i) {
            if (a[i] > max_val) {
                loc = i;
                max_val = a[i];
            }
        }
        order[cnt - 1] = loc + 1;
        val += (cnt - 1) * a[loc] + 1;
        a[loc] = -1;
    }
    cout << val << endl;
    for (int i = 0; i < N; ++i) cout << order[i] << " ";
    cout << endl;
    return 0;
}
