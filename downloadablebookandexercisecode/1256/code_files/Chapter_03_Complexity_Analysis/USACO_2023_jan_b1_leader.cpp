// http://usaco.org/index.php?page=viewproblem2&cpid=1275

#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    string str;
    cin >> str;

    int es[N];
    for (int i=0; i<N; ++i) cin >> es[i];

    for (int i=0; i<N; ++i)  --es[i];

    // Will make life easier
    // find first/last G/H
    int h0=N,h1=0,g0=N,g1=0;
    for (int i=0; i<N; ++i) {
        if (str[i]=='H') {
            h0 = i;
            break;
        }
    }
    for (int i=N-1; i>=0; --i) {
        if (str[i]=='H') {
            h1 = i;
            break;
        }
    }
    for (int i=0; i<N; ++i) {
        if (str[i]=='G') {
            g0 = i;
            break;
        }
    }
    for (int i=N-1; i>=0; --i) {
        if (str[i]=='G') {
            g1 = i;
            break;
        }
    }


    // Assume G leader is first.
    // Find if the first H contains all.
    int cnt = 0;
    if (es[h0]>=h1){
        // How many G's before that either included all G's or the H
        for (int i=0; i<h0; i++){
                if ((i==g0 && es[i] >= g1) || es[i] >=h0) cnt++;
        }
    }

    // Assume H leader is first.
    // Find if the first G contains all.
    if (es[g0]>=g1){
        // How many H's before that either included all H's or the G
        for (int i=0; i<g0; i++){
            if ((i==h0 && es[i] >= h1) || es[i] >=g0) cnt++;
        }
    }


    cout << cnt << endl;

}
