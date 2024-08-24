#include <iostream>

using namespace std;

int main() {

    string input_string = "NENENEESSWSWWW";

    int top_y = -1;
    char direction_top_y = ' ';

    int x = 0, y = 0;

    for ( int i = 0; i < input_string.length(); ++i ) {
        if ( input_string[i] == 'W' ) x -=1 ;
        if ( input_string[i] == 'E' ) x +=1 ;
        if ( input_string[i] == 'S' ) y -=1 ;
        if ( input_string[i] == 'N' ) y +=1 ;

        if ( input_string[i] == 'W' || input_string[i] == 'E' ) {
            if ( y > top_y) {
                top_y = y;
                direction_top_y = input_string[i];
            }
        }
    }
    string ans;
    if ( direction_top_y == 'W' ) ans = "CCW";
    else ans = "CW";

    cout << ans;

    return 0;
}
