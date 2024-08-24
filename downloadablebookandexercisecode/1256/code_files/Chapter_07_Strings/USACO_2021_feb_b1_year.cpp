#include <iostream>

#include <string>

using namespace std;

int main(){

    int N;
    cin >> N;

    string years[]={"Ox", "Tiger", "Rabbit", "Dragon", "Snake",
                    "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    string cow_name[N+1];
    int cow_age[N+1];
    int cow_year[N+1];

    cow_name[0]="Bessie";
    cow_age[0] = 0;
    cow_year[0] = 0;

    string cow_to, cow_from, tmp;
    string b4next, year_sign;
    for (int i=1; i<=N; ++i){
        cin >> cow_to >> tmp >> tmp >> b4next >> year_sign >> tmp >> tmp >> cow_from;
        cow_name[i] = cow_to;
        for (int j=0; j<12; ++j) {
            if (year_sign == years[j]) {
                cow_year[i] = j;
                break;
            }
        }

        int cow_from_ind;
        for (int j=0; j<i; ++j) {
            if (cow_from == cow_name[j]) {
                cow_from_ind = j;
                break;
            }
        }
        if (b4next == "next"){
            cow_age[i] = cow_age[cow_from_ind] + (cow_year[i] - cow_year[cow_from_ind] + 12) % 12;
            if (cow_year[i] == cow_year[cow_from_ind])
                cow_age[i] += 12;
        } else {
            cow_age[i] = cow_age[cow_from_ind] - (cow_year[cow_from_ind] - cow_year[i] + 12) % 12;
            if (cow_year[i] == cow_year[cow_from_ind])
                cow_age[i] -= 12;
        }

    }
    for (int j=0; j<N+1; ++j) {
        if ("Elsie" == cow_name[j]) {
            cout << abs(cow_age[j]) << endl ;
            break;
        }
    }

    return 0;
}