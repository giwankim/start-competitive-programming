#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream s_in{"cowfind.in"};

    int total = 0;
    char ch, prev_ch = ' ';
    int l_legs = 0;

    while (s_in >> ch){
        if (ch == '(' && prev_ch == '(') l_legs++;
        if (ch == ')' && prev_ch == ')') total += l_legs;
        prev_ch = ch;
    }


    ofstream s_out{"cowfind.out"};
    s_out << total;
    return 0;
}
