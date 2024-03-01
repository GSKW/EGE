#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>

using namespace std;
typedef long long int ll;


int main(){
    ifstream fin("/Users/IGrinyuk/Downloads/26-13.txt");
    ll N; fin >> N;
    vector<ll> vec;
    for(ll i = 0; i < N; i++){
        ll num; fin >> num;
        vec.push_back(num);
    }
    set<ll> st;
    for(auto it: vec){
        st.insert(it);
    }
    vector<ll> ans;
    for(ll i = 0; i < N; i++){
        for(ll j = i + 1; j < N; j++){
            ll a = vec[i], b = vec[j];
            if (a % 2 == 0) continue;
            if (b % 2 == 0) continue;
            ll mn = (a + b) / 2;
            if (st.find(mn) != st.end()){
                ans.push_back(mn);
            }

        }
    }
    cout << ans.size() << " " << *max_element(ans.begin(), ans.end()) << endl;
    return 0;
}