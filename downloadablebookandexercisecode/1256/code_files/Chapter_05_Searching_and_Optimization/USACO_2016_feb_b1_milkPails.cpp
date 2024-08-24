// http://usaco.org/index.php?page=viewproblem2&cpid=615
#include <iostream>

using namespace std;

int main() {

    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);

    int X, Y, M;
    cin >> X >> Y >> M;
    int max_val{0};

    for (int i = 0; i <= M / X; ++i) {
        int left = M - i * X;
        int rem = left % Y;
        if ((M - rem) > max_val) max_val = M - rem;
    }

    cout << max_val;

    return 0;
}
