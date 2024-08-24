#include <iostream>

using namespace std;


int time_guard[1001];

int main() {

    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);


    int N;
    cin >> N ;

    int start_time[N], end_time[N];
    for (int i=0; i<N; i++){
        cin >> start_time[i] >> end_time[i];
    }

    for (int i=0; i<N; i++){
        for (int t=start_time[i]; t< end_time[i]; ++t) {
            time_guard[t]++;
        }
    }

    int time_covered = 0;
    for (int i=0; i<1001; i++){
        if(time_guard[i]>0)
            time_covered++;
    }


    int min_cnt = 1001;
    for (int i=0; i<N; ++i){
        int cnt = 0;
        for (int t=start_time[i]; t< end_time[i]; ++t) {
            if ( time_guard[t]==1) cnt++;
        }
        min_cnt = min(min_cnt,cnt);
    }

    cout << (time_covered-min_cnt) <<endl;
    return 0;
}
