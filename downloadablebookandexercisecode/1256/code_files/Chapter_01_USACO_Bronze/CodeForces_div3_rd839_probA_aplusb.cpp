// https://codeforces.com/contest/1772/problem/A

#include <iostream>

using namespace std;

int main() {
    int t;
    string str;

    cin >> t;
    for (int i=0; i<t; ++i){
        cin >> str;
        int val = (str[0]-'0') + (str[2]-'0');
        cout << val << endl;
    }

}
