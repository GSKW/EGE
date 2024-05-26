#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
typedef long long int ll;
using namespace std;

/*
 * Stupid bullshit by Л. Шастин
 * № 32113
 * 27 № 5313
*/


int main(){
    fstream fin("C:/Users/bolevard/Downloads/27-117b.txt");
    ll N, D; fin >> N >> D;
    vector<ll> vec;
    for (ll i = 0; i < N; i++){
        ll num; fin >> num;
        vec.push_back(num);
    }
    ll mx = *max_element(vec.begin(), vec.end());
    vector <vector<ll>> mp(mx + 1);
    vector<ll> prefix_sum;
    prefix_sum.push_back(vec[0]);
    for (ll i = 1; i < N; i++){
        prefix_sum.push_back(prefix_sum[i-1] + vec[i]);
    }
    vector<ll> last(mx + 1);
    fill(last.begin(), last.end(), 0);
    for (ll i = 0; i < N; i++){
        ll curr = vec[i];
        if (last[curr] == 0){
            last[curr] = prefix_sum[i];
        }
        else{
            mp[curr].push_back(prefix_sum[i] - last[curr]);
            last[curr] = prefix_sum[i];
        }
    }
    vector<vector<ll>> pref_by_num(mx + 1);
    for(ll i = 0; i < mp.size(); i++){
        if (!mp[i].empty()){
            vector<ll> tmp;
            tmp.push_back(0);
            for (ll j = 0; j < mp[i].size(); j++){
                tmp.push_back(tmp[j] + mp[i][j]);
            }
            pref_by_num[i] = tmp;
        }
    }
    set<ll> st;
    st.insert(vec.begin(), vec.end());
    ll ans = 0;
    for (auto num: st){
        for (ll i = 0; i < pref_by_num[num].size(); i++){
            for(ll j = i + 1; j < pref_by_num[num].size(); j++){
                ll a = pref_by_num[num][j];
                ll b = pref_by_num[num][i];
                ll f = a - num - b;
                if (f % D == 0 && (f > 0)){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}