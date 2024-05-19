#include <iostream>
#include <fstream>
#include <vector>
typedef long long int ll;
using namespace std;


ll f(ll n){
    return (n + 1) * n / 2;
}

// 5103

int main(){
    fstream fin("C:/Users/bolevard/Downloads/27-104b.txt");
    ll N; fin >> N;
    vector<ll> vec;
    for(ll i = 0; i < N; i++){
        ll num; fin >> num;
        vec.push_back(num);
    }
    ll cur = 0;
    vector<ll> ans;
    ll last = 1;
    const ll M = 4043520;
    for(ll i = 0; i < N; i++){
        ll new_num = vec[i] * last;
        if ((new_num < M) && (M % new_num == 0)){
            last *= vec[i];
            cur += 1;

        }
        else{
            ans.push_back(cur);
            last = 1;
            cur = 0;
        }
    }
    ans.push_back(cur);
    ll final = 0;

    for(auto it: ans){
        final += f(it);
    }

    cout << final << endl;
    return 0;
}