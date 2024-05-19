#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

typedef long long int ll;
using namespace std;

int main(){
    fstream fin("C:/Users/bolevard/Downloads/27-B.txt");
    ll N; fin >> N;
    ll n13 = 0;
    ll n13_0 = 0, n13_1 = 0;
    ll n0 = 0, n1 = 0;
    for(ll i = 0; i < N; i++){
        ll num; fin >> num;
        if (num % 13 == 0){
            if (num % 2 == 0){
                n13_0++;
            }
            else n13_1++;
        }
        else{
            if (num % 2 == 0){
                n0++;
            }
            else n1++;
        }
    }
    ll s = 0;
    s += n0 * n13_1;
    s += n1 * n13_0;
    s += n13_0 * n13_1;
    cout << s << endl;

    return 0;
}