#include <iostream>
#include <string>

using namespace std;

/*
Input:
6
BESSIE
Ans:
25

Input:
4
BESS
Ans:
10

Input:
14
BESSIEBEBESSIE
Ans:
53
 */


int main() {

    int N;
    cin >> N;

    string str;
    cin >> str;

    string name = "BESSIE";
    int pts = 0;


    /* Method 1
    */
    for (int len = 1; len <= name.length(); ++len) {
        string name_sub = name.substr(0, len);
        int pos = 0;
        while ((pos = str.find(name_sub, pos)) != string::npos) {
            pts += len;
            if (len == name.length()) 
                pts += 4;
            pos += len;
        }
    }

    /* Method 2
    int name_index = 0;
    for (int i = 0; i < N; ++i){
        if (str[i] == name[name_index]) {
            name_index++;
            pts += name_index;
            if (name_index == name.length()){
                pts += 4; // completing 6 points to 10 points for full name
                name_index = 0;
            }
        }
        else {
            name_index = 0;
            if (str[i] == name[name_index]) {
                name_index++;
                pts += name_index;
            }
        }
    }
    /**/
    cout << pts;

}
