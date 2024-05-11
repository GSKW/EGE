#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

typedef long long int ll;

using namespace std;

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/107_27_B.txt");
    ll N; fin >> N;
    deque<ll> d;
    vector<ll> ans;
    for(ll i = 0; i < N; i++){
        ll num; fin >> num;
        d.push_back(num);
    }
    ll n = d.size() / 2 - 1;
    ll s_l = 0, s_r = 0;
    ll s_part_l = 0, s_part_r = 0;
    for(ll i = 0; i < N; i++){
        if (i < n){
            s_l += d[i] * abs(i - n) * 3;
            s_part_l += d[i];
        }
        if (i > n){
            s_r += d[i] * abs(i - n) * 3;
            s_part_r += d[i];
        }
    }
    ans.push_back(s_l + s_r);
    for (ll i = 1; i < N; i++){
        ll last = d.back();
        d.pop_back();
        d.push_front(last);
        s_l = s_l - s_part_l + last * n;
        s_part_l = s_part_l - d[n] + last;
        s_r = s_r + s_part_r + d[n + 1] - last*(N-2);
        s_part_r = s_part_r - last + d[n + 1];
        ans.push_back(s_l + s_r);
    }
    // 2 1 0 3 4 5
    cout << *min_element(ans.begin(), ans.end()) * 3 << endl;
//    cout << 7 + 8 + 40 + 15 + 26;

    return 0;
}