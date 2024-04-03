#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=41001

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/26-20.txt");
    ll N; fin >> N;
    vector<pair<ll, ll> > vec;
    ll start_experiment = 1633046400;
    ll start_week = 1634515200;
    ll end_week = start_week + 7 * 24 * 60 * 60;

//    ll start_experiment = 0;
//    ll start_week = 4;
//    ll end_week = 9;
    for(ll i = 0; i < N; i++){
        ll num_in, num_out;
        fin >> num_in >> num_out;
        if (num_in == 0){
            num_in = start_experiment;
        }
        if (num_out == 0){
            num_out = end_week;
        }
        vec.push_back(make_pair(num_in, 1));
        vec.push_back(make_pair(num_out, -1));
    }
    vec.push_back(make_pair(start_week, 0));
    vec.push_back(make_pair(end_week, 0));
    sort(vec.begin(), vec.end());
    ll mx = 0;
    ll cur_len = 0;
    ll num_process_start = -1;
    ll point_index_start = -1;
    for (ll i = 0; i < vec.size(); i++){
        cur_len += vec[i].second;
        if ((start_week <= vec[i].first) && (vec[i].first <= end_week)){
            if (num_process_start == -1){
                num_process_start = cur_len;
            }
            if (point_index_start == -1){
                point_index_start = i;
            }
            mx = max(mx, cur_len);
        }
    }
    ll cur_num_process = num_process_start;
    ll arr[end_week - start_week];
    ll t = point_index_start;

    for (ll i = start_week; i < end_week; i++){
        while (i == vec[t].first) {
            cur_num_process += vec[t].second;
            t++;
        }
        arr[i - start_week] = cur_num_process;
    }
    ll ans = 0;
    for (ll i = 0; i < end_week - start_week; i++){
        if (arr[i] == mx) ans++;
    }
    cout << mx << " " << ans << endl;
    return 0;
}