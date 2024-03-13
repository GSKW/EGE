#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=37161

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/26-17.txt");
    ll N; fin >> N;
    vector<vector<ll> > vec(1e5);
    for(ll i = 0; i < N; i++){
        ll n1, n2; fin >> n1 >> n2;
        n1--; n2--;
        vec[n1].push_back(n2);
    }
    for(ll i = 0; i < vec.size(); i++){
        if (vec[i].empty()) continue;
        sort(vec[i].begin(), vec[i].end());
    }
    for(ll i = vec.size() - 1; i >= 0; i--){
        if (vec[i].size() < 2) continue;
        for(ll j = 0; j < vec[i].size() - 1; j++){
            ll a = vec[i][j], b = vec[i][j + 1];
            if ((b - a) == 3){
                cout << i + 1 << " " << a + 2 << endl;
                return 0;
            }
        }
    }
    return 0;
}