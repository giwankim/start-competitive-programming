

#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("censor.in", "r", stdin);
    string str, T;
    cin >> str >> T;

    string out;
    /*
    out = str;
    int found = out.find(T);
    while (found != string::npos) {
        string o1 = out.substr(0, found) ;
        string o2 = out.substr(found+T.length());
        out = o1 + o2;

        found = out.find(T);
    }
    */
    // build it character by character
    out = "";
    int Tl = T.length();
    for (int i=0; i<str.length(); ++i){
        out += str[i];
        if (out.length() >= Tl){
            if (out.substr(out.length()-Tl) == T) {
                //out = out.substr(0, out.length()-Tl); <-- even this was too slow for the last case
                out.resize(out.length()-Tl);

            }
        }
    }


    freopen("censor.out", "w", stdout);
    cout << out;

    return 0;
}