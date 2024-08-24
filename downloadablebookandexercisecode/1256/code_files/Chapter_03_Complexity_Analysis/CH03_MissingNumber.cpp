#include <iostream>

using namespace std;

int main() {
    
    // CH03_MissingNumber.txt
    // is a text file, to simulate input from keyboard.
    // it's mere content is:
    // 8
    // 2 1 8 6 7 4 3
    freopen("CH03_MissingNumber.txt","r",stdin);
    
    int N;
    cin >> N;
    
    int sum_all = (N * (N + 1)) / 2;
    int sum_input = 0;
    
    for (int i = 0; i < N - 1; ++i ) {
        int t;
        cin >> t;
        sum_input += t;
    }
    
    int answer = sum_all - sum_input;
    
    cout << answer << '\n';
    
}
