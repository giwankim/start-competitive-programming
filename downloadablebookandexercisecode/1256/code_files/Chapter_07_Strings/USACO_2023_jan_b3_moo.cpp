#include <iostream>

using namespace std;

int main() {

    int Q;
    cin >> Q;

    for(int q=0; q<Q; ++q){
        string str;
        cin >> str;

        int ans = -1;
        int l = str.length();
        for(int i=0; i<=l-3 ; ++i){
            string s = str.substr(i,3);
            if (s=="MOO"){
                ans = l-3;
                break;
            }
            if (s=="MOM" || s=="OOO"){
                ans = l-3+1;
            }
            if (s=="OOM" && ans == -1){
                ans = l-3+2;
            }
        }
        cout << ans << endl;

    }

    return 0;
}
