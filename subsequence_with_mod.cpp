#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=41001

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/27_B.txt");
    ll N; fin >> N;
    vector<ll> vec;
    for (ll i = 0; i < N; i++){
        ll num; fin >> num;
        vec.push_back(num);
    }
    vector<ll> pref;
    pref.push_back(vec[0]);
    for (ll i = 1; i < N; i++){
        pref.push_back(pref[i - 1] + vec[i]);
    }
    vector<vector<ll> > pref_div;
    pref_div.resize(89);
    for (ll i = 0; i < N; i++) {
        pref_div[pref[i] % 89].push_back(i);
    }
    ll mx = 0;
    for(ll i = 0; i < pref_div.size(); i++){
        if (pref_div[i].size() < 2) continue;
        ll left = *pref_div[i].begin();
        ll right = *pref_div[i].rbegin();
        mx = max(mx, right - left);
    }
    cout << mx << endl;

    return 0;
}