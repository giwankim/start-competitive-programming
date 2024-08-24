// http://usaco.org/index.php?page=viewproblem2&cpid=430

#include <iostream>

using namespace std;

bool interesting(long long i) {
    string s = to_string(i);
    char a = s[0];
    char b = 0;
    int a_count = 0;
    int b_count = 0;

    for (int l = 0; l < s.length(); ++l) {
        if (s[l] == a) {
            a_count++;
            continue;
        }
        if (s[l] == b) {
            b_count++;
            continue;
        }
        if (b == 0) {
            b = s[l];
            b_count = 1;
            continue;
        }

        return false;

    }

    if (b_count == 1 || a_count == 1) return true;

    return false;
}

int main() {
    freopen("odometer.in", "r", stdin);
    freopen("odometer.out", "w", stdout);

    long long x, y;
    long long moos = 0;

    cin >> x >> y;

    /***************
    *
    * brute force solution, which does not work for time compelxity!
    *
    ****************/
    /*
    for (long long i=x; i<=y; ++i){
        if (interesting(i)) {
            moos++;
        }
    }
    */

    /***************
    *
    * Just going over the plausible numbers, and seeing if these are i the current domain!
    *
    ****************/

    // l: size of created number
    // a: The majority digit
    // b: The minority digit
    // p: Place of the minority digit
    for (int l = 3; l <= 17; ++l) {
        for (int a = 0; a <= 9; ++a) {
            string str_a(l, to_string(a)[0]);
            for (int b = 0; b <= 9; ++b) {
                if (b == a) continue;
                char char_b = to_string(b)[0];
                for (int p = 0; p < l; ++p) {
                    string s = str_a;
                    s[p] = char_b;
                    if (s[0] == '0') continue;
                    if (stoll(s) >= x && stoll(s) <= y) {
                        //cout << stoll(s) << "\n";
                        moos++;
                    }
                }
            }
        }

    }


    cout << moos;
    return 0;
}
