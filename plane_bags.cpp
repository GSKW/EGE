#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=57433

int main(){
    ifstream fin("/Users/IGrinyuk/Downloads/1_26.txt");
    ll K, N; fin >> K >> N;
    vector<pair< ll, ll> > vec_in, vec_out;
    for(ll i = 0; i < N; i++){
        ll n1, n2; fin >> n1 >> n2;
        vec_in.push_back(make_pair(n1, i));
        vec_out.push_back(make_pair(n2, i));

    }
    sort(vec_in.begin(), vec_in.end());
    sort(vec_out.begin(), vec_out.end());
    set<ll> st;
    for(ll i = 1; i <= K; i++){
        st.insert(i);
    }
    vector<ll> arr(N);
    fill(arr.begin(), arr.end(), -1);
    ll t1 = 0, t2 = 0, n = 0, last = -1;
    for (ll i = 0; i <= 1440; i++){
        while(t1 < vec_in.size() && i == vec_in[t1].first){
            ll num = vec_in[t1].second;
            if (!st.empty()){
                ll first_elem = *st.begin();
                arr[num] = first_elem;
                st.erase(first_elem);
                n++;
                last = first_elem;
            }
            t1++;
        }
        while(t2 < vec_out.size() && i == vec_out[t2].first){
            ll num = vec_out[t2].second;
            ll cell = arr[num];
            if (cell != -1){
                st.insert(cell);
                arr[num] = -1;
            }
            t2++;
        }
    }
    cout << n << " " << last << endl;
    return 0;
}