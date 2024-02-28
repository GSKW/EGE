#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=58534

int main() {
    fstream fin("/Users/IGrinyuk/Downloads/26-7.txt");
    vector<pair<ll, pair<ll, ll> > > vec_in, vec_out;
    ll Ka = 70, Kb = 30;
    int N; fin >> N;
    for (ll i = 0; i < N; i++){
        ll n1, n2; char type;
        fin >> n1 >> n2 >> type;
        if (type == 'A'){
            vec_in.push_back(make_pair(n1, make_pair(0, i)));
            vec_out.push_back(make_pair(n1 + n2, make_pair(0, i)));
        }
        else{
            vec_in.push_back(make_pair(n1, make_pair(1, i)));
            vec_out.push_back(make_pair(n1 + n2, make_pair(1, i)));
        }
    }
    sort(vec_in.begin(), vec_in.end());
    sort(vec_out.begin(), vec_out.end());
    set<ll> st_a, st_b;
    vector<pair<ll, ll> > arr(N);
    fill(arr.begin(), arr.end(), make_pair(-1, -1));
    for(ll i = 1; i <= Ka; i++){st_a.insert(i);}
    for(ll i = 1; i <= Kb; i++){st_b.insert(i);}
    ll t1 = 0, t2 = 0, n1 = 0, n2 = 0, t = max(vec_in[N-1].first, vec_out[N-1].first);
    for(ll i = 0; i <= t; i++){
        while(t2 < vec_out.size() && i == vec_out[t2].first){
            ll num = vec_out[t2].second.second;
            if (arr[num].first != -1){
                ll cell = arr[num].first;
                ll tp = arr[num].second;
                if (tp == 0){
                    st_a.insert(cell);
                }
                else{
                    st_b.insert(cell);
                }
                arr[num] = make_pair(-1, -1);
            }
            t2++;
        }
        while(t1 < vec_in.size() && i == vec_in[t1].first) {
            ll type = vec_in[t1].second.first;
            ll num = vec_in[t1].second.second;
            if (type == 0) {
                if (!st_a.empty()) {
                    ll first_element = *st_a.begin();
                    arr[num] = make_pair(first_element, 0);
                    st_a.erase(first_element);
                } else if (!st_b.empty()) {
                    ll first_element = *st_b.begin();
                    arr[num] = make_pair(first_element, 1);
                    st_b.erase(first_element);
                }
                else{
                    n1++;
                }
            } else {
                if (!st_b.empty()) {
                    ll first_element = *st_b.begin();
                    arr[num] = make_pair(first_element, 1);
                    st_b.erase(first_element);
                    n2++;
                }
                else{
                    n1++;
                }

            }
            t1++;
        }

    }

    cout << n2 << " " << n1 << endl;
    return 0;
}

