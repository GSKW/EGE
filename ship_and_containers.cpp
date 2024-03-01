#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=59853

int main(){
    ifstream fin("/Users/IGrinyuk/Downloads/26_14.txt");
    ll N; fin >> N;
    vector<ll> boxes, items;
    for(ll i = 0; i < N; i++){
        ll item, box; fin >> item >> box;
        boxes.push_back(box);
        items.push_back(item);
    }
    sort(items.begin(), items.end());
    sort(boxes.begin(), boxes.end());
    ll k = 0, mx = 0;
    for(ll i = (N - 1); i >= 0; i--){
        for (ll j = (N - 1); j >= 0; j--){
            if (items[i] <= boxes[j]){
                boxes[j] = 0;
                mx = max(mx, items[i]);
                k++;
            }
        }
    }
    cout << k << " " << mx;
    return 0;
}