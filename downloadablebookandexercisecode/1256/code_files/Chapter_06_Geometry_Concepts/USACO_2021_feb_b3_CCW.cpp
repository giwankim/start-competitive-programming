#include <iostream>

#include <string>

using namespace std;

int main() {

    int N;
    cin >> N;

    for (int n = 0; n < N; ++n) {

        string str;
        cin >> str;

        // We'll just sum the angles as we move along
        int ang = 0;
        for (int i = 0; i < str.size(); ++i) {
            char dir = str[i];
            char prev_dir;
            if (i > 0) prev_dir = str[i - 1];
            else prev_dir = str[str.length() - 1];

            if (dir == 'W' && prev_dir == 'S') ang += 90;
            if (dir == 'W' && prev_dir == 'N') ang -= 90;

            if (dir == 'E' && prev_dir == 'S') ang -= 90;
            if (dir == 'E' && prev_dir == 'N') ang += 90;

            if (dir == 'N' && prev_dir == 'W') ang += 90;
            if (dir == 'N' && prev_dir == 'E') ang -= 90;

            if (dir == 'S' && prev_dir == 'W') ang -= 90;
            if (dir == 'S' && prev_dir == 'E') ang += 90;

        }


        string out = "How did we get here";
        if (ang == 360) out = "CW";
        if (ang == -360) out = "CCW";

        cout << out << endl;
    }
    return 0;
}
