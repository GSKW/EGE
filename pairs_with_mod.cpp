#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=27991

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/27991_B.txt");
    ll N; fin >> N;
    vector<ll> vec, sorted_vec;
    for(ll i = 0; i < N; i++){
        ll num; fin >> num;
        vec.push_back(num);
    }
//    cout << N << endl;
    auto max_iter = max_element(vec.begin(), vec.end());
    ll max_elem = *max_iter;
    ll max_2_17 = 0;
    for(ll i = 0; i < N; i++){
        if(vec[i] % 2 == 0 && vec[i] % 17 == 0){
            max_2_17 = max(max_2_17, vec[i]);
        }
    }
    ll s1 = max_elem + max_2_17;
    sort(vec.begin(), vec.end());
    ll max_1_17 = 0;
    ll max_1 = 0;
    for(ll i = vec.size() - 1; i >= 0; i--){
        if (vec[i] % 2 == 1 && vec[i] % 17 == 0){
            max_1_17 = vec[i];
            break;
        }
    }
    for(ll i = vec.size() - 1; i >= 0; i--){
        if (vec[i] % 2 == 1){
            max_1 = vec[i];
            break;
        }
    }
    ll s2 = max_1 + max_1_17;
//    cout << s1 << " " << s2 << endl;
    cout << max_elem << " " << max_2_17 << endl;
    return 0;
}