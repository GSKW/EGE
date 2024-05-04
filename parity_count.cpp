#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=33772

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/27-B-4.txt");
    ll N; fin >> N;
    ll n_0 = 0, n_1 = 0, s = 0;
    vector<pair<ll, ll> > vec;
    for(ll i = 0; i < N; i++){
        ll n1, n2; fin >> n1 >> n2;
        ll mn = min(n1, n2);
        s += mn;
        if (mn % 2 == 0){n_0++;}
        else{n_1++;}
        vec.push_back(make_pair(abs(n1 - n2), (mn % 2) - ((n1+n2-mn) % 2)));
    }

    // н -> ч
    // 1 - 0 = 1
    ll mn_1 = 1e9;
    for(ll i = 0; i < N; i++){
        if (vec[i].second == 1){
            mn_1 = min(vec[i].first, mn_1);
        }
    }

    // ч -> н
    // ч -> н
    // 0 - 1 = -1
    ll mn_0_1 = 1e9;
    ll mn_0_2 = 1e9;
    for(ll i = 0; i < N; i++){
        if (vec[i].second == -1){
            if(vec[i].first < mn_0_1){
                mn_0_2 = mn_0_1;
                mn_0_1 = vec[i].first;
            }
            else if(vec[i].first < mn_0_2){
                mn_0_2 = vec[i].first;
            }
        }
    }

    ll s1 = s + mn_1;
    ll s2 = s + mn_0_1 + mn_0_2;
    cout << min(s1, s2) << endl;

    return 0;
}