#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
typedef long long int ll;

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/26-20.txt");
    ll N; fin >> N;
    vector<pair<ll, ll> > points;
    for(ll i = 0; i < N; i++){
        ll num_in, num_out;
        fin >> num_in >> num_out;
//
//        ll time_off = 1634515200 + 7 * 24 * 60 * 60;
//        ll time_on = 1634515200;
        ll time_off = 9;
        ll time_on = 4;

        if (num_out == 0){
//            num_out = 1634515200 + 7 * 24 * 60 * 60;
            num_out = 1e15;
        }

        if (num_out <= time_on){
//            cout << num_in << "    " << num_out << endl;
            continue;
        }
        if (num_in >= time_off) {
//            cout << num_in << " " << num_out << endl;
            continue;
        };

        if (num_out > time_off){num_out = time_off;}
        if (num_in < time_on){num_in = time_on;}


        if (num_out < num_in){
            cout << "+" << endl;
        }
        cout << num_in << " " << num_out << endl;
        points.push_back(make_pair(num_in, 1));
        points.push_back(make_pair(num_out, -1));
    }
    sort(points.begin(), points.end());
    ll cur_experiments = 0;
    ll mx_experiments = 0;
    for(ll i = 0; i < points.size(); i++){
        cur_experiments += points[i].second;
//        cout << points[i].first << " " << points[i].second << endl;
        mx_experiments = max(mx_experiments, cur_experiments);
    }

    cout << mx_experiments << endl;

    return 0;
}