#include <iostream>

#include <vector>
#include <map>
#include <utility>

using namespace std;

int main() {

    freopen("evolution.in","r",stdin);
    freopen("evolution.out","w",stdout);

    int N;
    cin >> N;

    vector<string> a[N];
    map<string,vector<int>> chars;

    for(int i=0; i<N; ++i){
        int K;
        cin >> K;
        string str;
        for(int j=0; j<K; ++j) {
            cin >> str;
            chars[str].push_back(i);
        }
    }


    string ans = "yes";

    for(auto c1: chars){
        for(auto c2: chars){
            if (c1.first == c2.first)
                continue;
            vector<int> c1_vec = c1.second;
            vector<int> c2_vec = c2.second;
            vector<int> s1, s2;
            if ( c1_vec.size() <= c2_vec.size()){
                s1 = c1_vec;
                s2 = c2_vec;
            } else {
                s1 = c2_vec;
                s2 = c1_vec;
            }

            int matches=0;
            for(int num1: s1){
                for(int num2: s2){
                    if (num1 == num2) {
                        matches++;
                        break;
                    }
                }
            }
            if ( !(matches==0 || matches == s1.size()) ){
                ans = "no";
                break;
            }

        }
        if (ans=="no")
            break;
    }

    cout << ans;

    return 0;
}
