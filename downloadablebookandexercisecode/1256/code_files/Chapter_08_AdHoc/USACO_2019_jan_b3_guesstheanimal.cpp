#include <iostream>

#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    freopen("guess.in","r",stdin);
    freopen("guess.out","w",stdout);

    int N;
    cin >> N;

    vector<string> A[N];

    for (int i=0; i<N; ++i){
      string str;
      int K;
      cin >> str >> K;
      for (int j=0; j<K; ++j) {
          cin >> str;
          A[i].push_back(str);
      }
    }
/*
 *  You can of course write a function to find the common:
int num_common(int i, int j)
{
  int count = 0;
  vector<string> &v1 = characteristics[i], &v2 = characteristics[j];
  for (int i=0; i<v1.size(); i++)
    for (int j=0; j<v2.size(); j++)
      if (v1[i] == v2[j]) count++;
  return count;
}
 *
 *
 */
    int max_common = 0;
    for (int i=0; i<N; ++i){
        set<string> S1{begin(A[i]), end(A[i])};

        for (int j=i+1; j<N; ++j) {
            set<string> S2{begin(A[j]), end(A[j])};

            set<string> S12;
            set_union (S1.begin(), S1.end(),
                           S2.begin(), S2.end(),
                           inserter(S12, S12.begin()));
            int common = S1.size() + S2.size() - S12.size();
            max_common = max(max_common, common);
        }
    }


    cout << max_common+1 << endl;
    return 0;
}
