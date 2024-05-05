#include <iostream>
#include <fstream>
#include <vector>

typedef long long int ll;
using namespace std;

vector<ll> vec;

pair<ll, ll> get_two_mn(ll ost){
    ll mn1 = 1e9, mn2 = 1e9;
    for(ll i = 0; i < vec.size(); i++){
        if (vec[i] % 10 == ost) {
            if (vec[i] < mn1) {
                mn2 = mn1;
                mn1 = vec[i];
            } else if (vec[i] < mn2) {
                mn2 = vec[i];
            }
        }
    }
    return make_pair(mn1, mn2);
}

ll get_mn(ll ost){
    ll mn = 1e9;
    for(ll i = 0; i < vec.size(); i++){
        if (vec[i] % 10 == ost){
            mn = min(mn, vec[i]);
        }
    }
    return mn;
}

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/27-47a.txt");
    ll N; fin >> N;
    ll mn = 0, mx = 0;
    for (ll i = 0; i < N; i++){
        ll n1, n2; fin >> n1 >> n2;
        vec.push_back(abs(n1 - n2));
        mn += min(n1, n2);
        mx += max(n1, n2);
    }

    // B
    // 8
    // 7 1
    // 6 2
    // 5 3
    // 4 4
    // 9 9
//    vector<ll> ans;
//    ans.push_back(mn + get_mn(8));
//    ans.push_back(mn + get_mn(7) + get_mn(1));
//    ans.push_back(mn + get_mn(6) + get_mn(2));
//    ans.push_back(mn + get_mn(5) + get_mn(3));
//    ans.push_back(mn + get_mn(4) + get_mn(4));
//    ans.push_back(mn + get_mn(9) + get_mn(9));

    // A
    // 1 2
    // 1 1 1
    // 3
    // 9 4
    // 8 5
    // 7 6
    //
//    vector<ll> ans;
//    ans.push_back(mn + get_mn(1) + get_mn(2));
//    ans.push_back(mn + get_mn(1) + get_mn(1) + get_mn(1));
//    ans.push_back(mn + get_mn(3));
//    ans.push_back(mn + get_mn(9) + get_mn(4));
//    ans.push_back(mn + get_mn(8) + get_mn(5));
//    ans.push_back(mn + get_mn(7) + get_mn(6));
//    cout << mx << " " << mn << endl;
//    cout <<*min_element(ans.begin(), ans.end());
//    for(auto it: ans){
//        cout << it <<endl;
//    }
    return 0;
}