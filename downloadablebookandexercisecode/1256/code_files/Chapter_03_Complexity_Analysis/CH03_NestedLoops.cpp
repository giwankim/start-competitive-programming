#include <iostream>

using namespace std;

int main() {

    int die1_sides = 6;
    int die2_sides = 6;

    int die1[6] = {1, 2, 3, 4, 5, 6};
    int die2[6] = {13, 24, 35, 43, 57, 68};

    for (int i = 0; i < die1_sides; ++i) {
        for (int j = 0; j < die2_sides; ++j) {
            int sum = die1[i] + die2[j];
            cout << sum << "\n";
        }
    }

    return 0;
}
