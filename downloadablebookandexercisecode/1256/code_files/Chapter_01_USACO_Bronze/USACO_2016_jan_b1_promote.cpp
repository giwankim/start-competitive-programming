// http://usaco.org/index.php?page=viewproblem2&cpid=591

#include <iostream>

using namespace std;

int main(){

    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);


    int b0, b1, s0, s1, g0, g1, p0, p1;
    cin >> b0 >> b1 >> s0 >> s1 >> g0 >> g1 >> p0 >> p1;

    int pm, gm, sm;
    pm = p1 - p0;
    gm = g1 - g0 + pm;
    sm = s1 - s0 + gm;

    cout << sm << endl;
    cout << gm << endl;
    cout << pm << endl;

}
