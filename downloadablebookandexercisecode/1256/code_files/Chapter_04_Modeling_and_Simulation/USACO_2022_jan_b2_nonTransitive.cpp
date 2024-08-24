#include <iostream>

using namespace std;

int firstWins(int A[], int B[]) {
    int a = 0, b = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (A[i] > B[j]) a++;
            if (A[i] < B[j]) b++;
        }
    }
    return a - b;
}

int main() {

    int T;
    cin >> T;

    int A[4], B[4];

    for (int t = 0; t < T; ++t) {

        for (int i = 0; i < 4; ++i)
            cin >> A[i];
        for (int i = 0; i < 4; ++i)
            cin >> B[i];

        // your Program

        string str = "no";
        for (int c1 = 1; c1 <= 10; ++c1) {
            for (int c2 = c1; c2 <= 10; ++c2) {
                for (int c3 = c2; c3 <= 10; ++c3) {
                    for (int c4 = c3; c4 <= 10; ++c4) {
                        int C[] = {c1, c2, c3, c4};

                        int a = 0, b = 0, c = 0;
                        int res = firstWins(A, B);
                        if (res > 0) a++;
                        if (res < 0) b++;

                        res = firstWins(A, C);
                        if (res > 0) a++;
                        if (res < 0) c++;

                        res = firstWins(B, C);
                        if (res > 0) b++;
                        if (res < 0) c++;

                        if (a == 1 && b == 1 && c == 1)
                            str = "yes";
                    }
                }
            }
        }

        cout << str << endl;
    }
    return 0;
}
