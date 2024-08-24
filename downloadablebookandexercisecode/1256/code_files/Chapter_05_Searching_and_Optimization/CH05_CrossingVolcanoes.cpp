#include <iostream>

using namespace std;

int main() {

    int N = 4;
    int K = 1;

    N = 4;

    /*****************************
     *
     *
     *  Note: The problem talks about coordinates (x,y).
     *  The program works with two-dimensional array.
     *  Therefore, the x translates to the columns, and the y to the rows.
     *  That can become confusing sometimes in the code, since:
     *  Volcano at location (3,2), means it's location is at x=3, y=2, which
     *  in the array then means [2][3].
     *
     *
     ******************************/


    /*
      int grid[5][5] = {{0,0,0,0,0},
                      {0,0,0,0,0},
                      {0,0,0,1,0},
                      {0,0,0,0,0},
                      {0,0,0,0,0}};
*/
    int grid[N + 1][N + 1];
    for (int r = 0; r < N + 1; ++r) {
        for (int c = 0; c < N + 1; ++c) {
            grid[r][c] = 0;
        }
    }
    grid[2][3] = 1;


    int path_count = 0;


    // One turn path

    bool safe = true;
    for (int c = 0; c <= N; ++c) {
        if (grid[0][c] == 1) safe = false;
    }
    for (int r = 0; r <= N; ++r) {
        if (grid[r][N] == 1) safe = false;
    }
    if (safe) path_count++;


    // Two turn path
    for (int c_turn = 1; c_turn < N; ++c_turn) {
        bool safe = true;

        for (int c = 0; c <= c_turn; ++c) {
            if (grid[0][c] == 1) safe = false;
        }
        for (int r = 0; r <= N; ++r) {
            if (grid[r][c_turn] == 1) safe = false;
        }
        for (int c = c_turn; c <= N; ++c) {
            if (grid[N][c] == 1) safe = false;
        }
        if (safe) path_count++;
    }


    // Three turn path
    for (int c_turn = 1; c_turn < N; ++c_turn) {
        for (int r_turn = 1; r_turn < N; ++r_turn) {

            bool safe = true;

            for (int c = 0; c <= c_turn; ++c) {
                if (grid[0][c] == 1) safe = false;
            }
            for (int r = 0; r <= r_turn; ++r) {
                if (grid[r][c_turn] == 1) safe = false;
            }
            for (int c = c_turn; c <= N; ++c) {
                if (grid[r_turn][c] == 1) safe = false;
            }
            for (int r = r_turn; r <= N; ++r) {
                if (grid[r][N] == 1) safe = false;
            }
            if (safe) path_count++;
        }
    }


    cout << path_count;
    return 0;

}