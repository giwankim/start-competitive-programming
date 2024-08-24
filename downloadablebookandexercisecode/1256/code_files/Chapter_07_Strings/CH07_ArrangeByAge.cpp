/*

Example 1:
4
Rosie was born in April after Bessie
Daisy was born in April before Rosie
Elsie was born in March before Daisy
Betty was born in August after Rosie

Answer: No

Example 2:
4
Rosie was born in April before Bessie
Daisy was born in April before Rosie
Elsie was born in April before Daisy
Betty was born in August after Rosie

Answer: Yes
*/

#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    string months[] = {"January", "February", "March", "April", 
    "May", "June", "July", "August", "September", "October",
    "November", "December"};
    string cow_name[N + 1];
    int cow_age[N + 1];
    int cow_month[N + 1];

    cow_name[0] = "Bessie";
    cow_age[0] = 0;
    cow_month[0] = 0;

    for (int i = 1; i <= N; ++i) {
        string cow_to, cow_from, tmp;
        string before_after, mon;
        cin >> cow_to >> tmp >> tmp >> tmp >> mon >> before_after >> cow_from;
        // Rosie was born in April after Bessie
        cow_name[i] = cow_to;
        for (int j = 0; j < 12; ++j) {
            if (mon == months[j]) {
                cow_month[i] = j;
                break;
            }
        }

        int cow_from_ind;
        for (int j = 0; j < i; ++j) {
            if (cow_from == cow_name[j]) {
                cow_from_ind = j;
                break;
            }
        }

        int month_to = cow_month[i];
        int month_from = cow_month[cow_from_ind];

        if (before_after == "after") {
            int diff_months = (month_to - month_from + 12) % 12;
            cow_age[i] = cow_age[cow_from_ind] + diff_months;
            if (cow_month[i] == cow_month[cow_from_ind])
                cow_age[i] += 12;
        } else {
            int diff_months = (month_from - month_to + 12) % 12;
            cow_age[i] = cow_age[cow_from_ind] - diff_months;
            if (cow_month[i] == cow_month[cow_from_ind])
                cow_age[i] -= 12;
        }

    }
    string ans = "No";
    for (int j = 0; j < N + 1; ++j) {
        if (cow_age[j] < -24) {
            ans = "Yes";
            break;
        }
    }

    cout << ans << endl;

}