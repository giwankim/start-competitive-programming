#include <iostream>

#include <map>
#include <string>

using namespace std;

int main() {

    map<string, int> names;

    int K, N;
    cin >> K >> N;

    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        names.insert(pair<string, int>(str, i));
    }

    char A[N][N];
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            A[r][c] = '?';
            if (r == c) A[r][c] = 'B';
        }
    }

    for (int k = 0; k < K; ++k) {
        string list[N];
        for (int i = 0; i < N; ++i)
            cin >> list[i];

        for (int i = 0; i < N - 1; ++i) {
            if (list[i + 1].compare(list[i]) < 0) {
                for (int i1 = 0; i1 <= i; ++i1) {
                    int ind1 = names[list[i1]];
                    for (int i2 = i + 1; i2 < N; ++i2) {
                        int ind2 = names[list[i2]];
                        A[ind1][ind2] = '0';
                        A[ind2][ind1] = '1';
                    }
                }
            }
        }

    }// read k lines

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cout << A[r][c];
        }
        cout << endl;
    }


    return 0;
}
