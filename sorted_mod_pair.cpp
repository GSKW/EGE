#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=28133

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/28133_B.txt");
    ll N; fin >> N;
    vector<multiset<ll> > vec;
    vector<pair<ll, pair<ll, ll> > > ans;
    vec.resize(120);
    for (ll i = 0; i < N; i++){
        ll num; fin >> num;
        if (!vec[(120 - num % 120) % 120].empty()){
            ll last_num = *vec[(120 - num % 120) % 120].rbegin();
            if (last_num > num){
                ans.push_back(make_pair(last_num + num, make_pair(last_num, num)));
            }
        }
        vec[num % 120].insert(num);
    }
    auto it = max_element(ans.begin(), ans.end());
    cout << it->second.first << " " << it->second.second;

    return 0;
}