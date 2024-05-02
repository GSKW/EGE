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
    vector<multiset<pair<ll, ll> > > vec;
    vec.resize(120);
    for(ll i = 0; i < N; i++){
        ll num; fin >> num;
        vec[num % 120].insert(make_pair(num, i));
    }
    vector<pair<ll, pair<ll, ll> > > ans;
    auto it = vec[0].rbegin();
    ll n1 = it->first; ll idx1 = it->second;
    it++;
    ll n2 = it->first; ll idx2 = it->second;
    if (idx1 > idx2){
        if(n1 <= n2){
            ans.push_back(make_pair(n1 + n2, make_pair(n1, n2)));
        }
    }
    else{
        if(n2 <= n1){
            ans.push_back(make_pair(n1 + n2, make_pair(n1, n2)));
        }
    }
    for (ll i = 1; i < 120; i++){
        if (!vec[i].empty() && !vec[120 - i].empty()) {
            auto it1 = vec[i].rbegin();
            ll num1 = it1->first; ll id1 = it1->second;
            auto it2 = vec[120 - i].rbegin();
            ll num2 = it2->first; ll id2 = it2->second;
            if (id1 > id2){
                if(num1 <= num2){
                    ans.push_back(make_pair(num1 + num2, make_pair(num1, num2)));
                }
            }
            else{
                if(num2 <= num1){
                    ans.push_back(make_pair(num1 + num2, make_pair(num1, num2)));
                }
            }
        }
    }
    auto mx = max_element(ans.begin(), ans.end());
    cout << mx->second.first << " " << mx->second.second << endl;
    return 0;
}