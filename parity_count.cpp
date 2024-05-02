#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=33772

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/27-B-4.txt");
    ll N; fin >> N;
    ll n_0 = 0, n_1 = 0, s = 0;
    vector<ll> vec;
    for(ll i = 0; i < N; i++){
        ll n1, n2; fin >> n1 >> n2;
        ll mn = min(n1, n2);
        s += mn;
        if (mn % 2 == 0){n_0++;}
        else{n_1++;}
        vec.push_back(abs(n1 - n2));
    }
    ll mn1_1 = 1e9;
    ll mn2_1 = 1e9;
    for (ll i = 0; i < vec.size(); i++){
        if (vec[i] % 2 == 1){
            if (vec[i] < mn1_1){
                mn2_1 = mn1_1;
                mn1_1 = vec[i];
            }
            else if(vec[i] < mn2_1){
                mn2_1 = vec[i];
            }
        }
    }

    ll mn1_0 = 1e9;
    ll mn2_0 = 1e9;
    for (ll i = 0; i < vec.size(); i++){
        if (vec[i] % 2 == 1){
            if (vec[i] < mn1_0){
                mn2_0 = mn1_0;
                mn1_0 = vec[i];
            }
            else if(vec[i] < mn2_0){
                mn2_0 = vec[i];
            }
        }
    }

    ll s1 = s + mn1_0 + mn2_0 + mn1_1;
    ll s2 = s + mn1_1 + mn2_1;

//    cout << "All: " << s % 2 << " |0: " << n_0 << " |1: " << n_1 << endl;
    cout << min(s1, s2) << endl;
    return 0;
}