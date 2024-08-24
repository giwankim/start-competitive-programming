
#include <iostream>

using namespace std;

int main() {

    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    // store just row and column location of each
    int Lr, Lc, Br, Bc, Rr, Rc;
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; ++c) {
            char ch;
            cin >> ch;
            if (ch == 'L') { Lc = c, Lr = r; }
            if (ch == 'B') { Bc = c, Br = r; }
            if (ch == 'R') { Rc = c, Rr = r; }
        }
    }
    int dist = abs(Lc - Bc) + abs(Lr - Br) - 1;
    if (Lr == Br && Lr == Rr &&
        ((Rc < Lc && Rc > Bc) || (Rc < Bc && Rc > Lc)))
        dist += 2;
    if (Lc == Bc && Lc == Rc &&
        ((Rr < Lr && Rr > Br) || (Rr < Br && Rr > Lr)))
        dist += 2;
    cout << dist << endl;

    return 0;
}
