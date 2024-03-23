#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=63043

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/27-B-3.txt");
    ll K, N; fin >> K >> N;
    vector<ll> vec;
    vector<ll> sorted_vec;
    for(ll i = 0; i < N; i++){
        ll num; fin >> num;
        vec.push_back(num);
        sorted_vec.push_back(num);
    }
    sort(sorted_vec.begin(), sorted_vec.end());
    auto max_iter = max_element(vec.begin(), vec.end());
    ll max_ind = max_iter - vec.begin();
    ll max_elem = *max_iter;
    if (((max_ind - 3 * K) < 0) || ((max_ind + 3 * K) > N)){
        cout << "+" << endl;
    }
    else{
        vector<pair<ll, pair<ll, ll> > > temp;
        for(ll i = 0; i < vec.size() - 3 * K; i++){
            temp.push_back(make_pair(vec[i] + vec[i + 3 * K], make_pair(vec[i], vec[i + 3 * K])));
        }
        auto max_iter2 = max_element(temp.begin(), temp.end());
        ll s =  max_iter2->first;
        ll a =  max_iter2->second.first;
        ll b =  max_iter2->second.second;
        cout << a << " " << b << " " << max_elem << endl;
        cout << a + b + max_elem << endl;
    }

    return 0;
}