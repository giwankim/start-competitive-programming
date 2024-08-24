#include <iostream>

using namespace std;


int main() {


    // Sample Input
    int N = 5;
    char rooms[5][5] = {{'.', '.', 'D', '.', '.'},
                        {'.', 'D', '.', '.', 'F'},
                        {'D', '.', '.', '.', 'D'},
                        {'.', 'F', '.', '.', '.'},
                        {'.', '.', '.', '.', 'D'}};


    int must_visit = 0;
    int optional_visit = 0;
    bool visited_food = false;
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (rooms[row][col] == 'D') {
                must_visit++;
                continue;
            }

            int cnt = 0;
            if (row > 0 && rooms[row - 1][col] == 'D') cnt++;
            if (row < N - 1 && rooms[row + 1][col] == 'D') cnt++;
            if (col > 0 && rooms[row][col - 1] == 'D') cnt++;
            if (col < N - 1 && rooms[row][col + 1] == 'D') cnt++;

            if (cnt >= 2) {
                optional_visit++;
                continue;
            }
            if (rooms[row][col] == 'F' && !visited_food) {
                visited_food = true;
                optional_visit++;
                continue; // We do not really need this continue
            }
        }
    }

    cout << must_visit << " " << must_visit + optional_visit << endl;

    return 0;
}
