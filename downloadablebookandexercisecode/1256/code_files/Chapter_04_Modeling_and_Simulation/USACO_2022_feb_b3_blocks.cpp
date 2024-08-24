#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    string B[4];

    for (int i = 0; i < 4; ++i)
        cin >> B[i];

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        bool canWrite = false;
        // Loop over the arrangement of the cubes
        // the most brute force.
        string Bs[4];
        for (int a = 0; a < 4 && !canWrite; ++a) {
            Bs[0] = B[a];
            for (int b = 0; b < 4 && !canWrite; ++b) {
                if (a == b) continue;
                Bs[1] = B[b];
                for (int c = 0; c < 4 && !canWrite; ++c) {
                    if (a == c || b == c) continue;
                    Bs[2] = B[c];
                    for (int d = 0; d < 4 && !canWrite; ++d) {
                        if (a == d || b == d || c == d) continue;
                        Bs[3] = B[d];
                        canWrite = true;
                        for (int l = 0; l < word.length(); ++l) {
                            string bs = Bs[l];
                            if (bs.find(word[l]) == -1) {
                                canWrite = false;
                                break;
                            }

                        }

                    }
                }
            }
        }
        if (canWrite) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }


    return 0;
}
