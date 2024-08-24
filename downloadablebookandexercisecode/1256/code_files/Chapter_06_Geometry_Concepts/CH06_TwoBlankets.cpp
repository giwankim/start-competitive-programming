#include <iostream>

using namespace std;

int main() {

    int x_1 = 20, y_1 = 10, x_2 = 50, y_2 = 50;
    int x_3 = 40, y_3 = 40, x_4 = 70, y_4 = 70;

    // Overlap in x
    int left_edge = max(x_1, x_3);
    int right_edge = min(x_2, x_4);
    int overlap_x = right_edge - left_edge;

    // Overlap in y
    int bottom_edge = max(y_1, y_3);
    int top_edge = min(y_2, y_4);
    int overlap_y = top_edge - bottom_edge;

    // Overlap area
    int overlap_area = overlap_x * overlap_y;
    overlap_area = max(overlap_area, 0);  // This line will be changed

    int area_blanket_1 = (x_2 - x_1) * (y_2 - y_1);
    int area_blanket_2 = (x_4 - x_3) * (y_4 - y_3);

    int total_area = area_blanket_1 + area_blanket_2 - overlap_area;

    cout << total_area;


    return 0;
}
