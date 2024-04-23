#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

// 10837

vector<ll> count(ll n){
    vector<ll> vec;
    for (ll i = 1; i * i < n; i++){
        if (n % i == 0){
            vec.push_back(i);
            vec.push_back(n / i);
        }
    }
    ll s = sqrtl(n);
    if (s * s == n){
        vec.push_back(s);
    }
    sort(vec.begin(), vec.end());
    return vec;
}

int main(){
    ll k = 0;
    for (ll i = 250001;;i++){
        vector<ll> div = count(i);
        ll S = 0;
        for (ll j = 0; j < div.size(); j++){
            vector<ll> div_div = count(div[j]);
            if (div_div.size() == 2){
                S += div[j];
            }
        }
        if ((S != 0) && (S % 17 == 0)){
            cout << i << " " << S << endl;
            k++;
            if (k == 5) break;
        }
    }

    return 0;
}