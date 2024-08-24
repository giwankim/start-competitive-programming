#include <iostream>

using namespace std;

int main() {

    freopen("typo.in","r",stdin);
    freopen("typo.out","w",stdout);

    string str;
    cin >> str;

    // Left to right, check for need to flip ')'<-- left  into '(' <-- right
    int cnt2 = 0;
    int cnt = 0;
    int ans = 0;
    for (int i=0; i<str.size(); ++i){
        if ( str[i]=='(' ){
            cnt++;
        } else {
            cnt--;
            cnt2++;
        }
        if (cnt < 0 ) {
            ans = cnt2;
            break;
        }
    }

    cnt2=0;
    cnt=0;
    if (ans==0) {
        for (int i = str.size()-1; i >=0; --i) {
            if (str[i] == ')') {
                cnt++;
            } else {
                cnt--;
                cnt2++;
            }
            if (cnt < 0) {
                ans = cnt2;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}
