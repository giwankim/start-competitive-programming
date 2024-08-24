#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    int N;
    string bessie, elssie;
    cin >> N >> bessie >> elssie;

    string mom[N], daughter[N];

    for (int i = 0; i < N; ++i) {
        cin >> mom[i] >> daughter[i];
    }

    vector<string> bs, es;
    bs.push_back(bessie);
    bool found = true;
    while (found) {
        string name = bs.back();
        found = false;
        for (int i = 0; i < N; i++) {
            if (daughter[i] == name) {
                found = true;
                bs.push_back(mom[i]);
                break;
            }
        }
    }

    es.push_back(elssie);
    found = true;
    while (found) {
        string name = es.back();
        found = false;
        for (int i = 0; i < N; i++) {
            if (daughter[i] == name) {
                found = true;
                es.push_back(mom[i]);
                break;
            }
        }
    }


    bool found_ancestor = false;
    int ee_ancestor, bs_ancestor;
    for (int bb = 0; bb < bs.size() && !found_ancestor; ++bb) {
        string name = bs[bb];
        for (int ee = 0; ee < es.size() && !found_ancestor; ++ee) {
            if (es[ee] == name) {
                found_ancestor = true;
                ee_ancestor = ee;
                bs_ancestor = bb;
            }
        }
    }

    if (ee_ancestor > bs_ancestor) {
        swap(ee_ancestor, bs_ancestor);
        swap(bessie, elssie);
    }

    if (!found_ancestor) {
        cout << "NOT RELATED" << endl;
        return 0;
    }
    if (ee_ancestor == 1 && bs_ancestor == 1) {
        cout << "SIBLINGS" << endl;
        return 0;
    }


    if (ee_ancestor == 0) {
        cout << elssie + " is the ";
        string str = "mother";
        if (bs_ancestor >= 2) str = "grand-" + str;
        for (int bb = 3; bb <= bs_ancestor; ++bb)
            str = "great-" + str;
        cout << str << " of " + bessie;
        return 0;
    }


    if (ee_ancestor == 1 && bs_ancestor > 1) {
        cout << elssie + " is the ";
        string str = "aunt";
        for (int bb = 3; bb <= bs_ancestor; ++bb)
            str = "great-" + str;
        cout << str << " of " + bessie;
        return 0;
    }


    cout << "COUSINS" << endl;

    return 0;
}
