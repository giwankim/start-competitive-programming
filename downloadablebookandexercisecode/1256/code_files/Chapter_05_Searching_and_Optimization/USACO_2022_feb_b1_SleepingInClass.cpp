#include <iostream>

using namespace std;

int main() {

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        int a[N];
        int largest = 0, total_sum = 0;

        for (int i = 0; i < N; i++) {
            cin >> a[i];
            largest = max(largest, a[i]);
            total_sum += a[i];
        }

        int cnt;
        for (int desired_sum = largest; desired_sum <= total_sum; ++desired_sum) {
            cnt = 0;
            int tmp_sum = a[0];
            for (int j = 1; j < N; j++) {
                if (tmp_sum > desired_sum) {
                    break;
                }
                if (tmp_sum == desired_sum) {
                    tmp_sum = a[j];
                    continue;
                }
                if (tmp_sum < desired_sum) {
                    tmp_sum += a[j];
                    cnt++;
                    continue;
                }
            }

            if (tmp_sum == desired_sum) {
                break;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}




