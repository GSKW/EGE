#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <deque>

using namespace std;
typedef long long int ll;

// https://inf-ege.sdamgia.ru/problem?id=63075

struct Person{
    ll time_in, duration, type;
};

bool Compare(Person a, Person b){
    return a.time_in < b.time_in;
}

deque<ll> update_deque(deque<ll> deque_, ll cur_timestamp, ll last_timestamp){
    ll delta = cur_timestamp - last_timestamp;
    while(delta > 0 && !deque_.empty()){
        delta -= deque_.front();
        deque_.pop_front();
    }
    if (delta < 0){
        deque_.push_front(abs(delta));
    }
    return deque_;
}

int main(){
    fstream fin("/Users/IGrinyuk/Downloads/26-18.txt");
    ll N; fin >> N;
    vector<Person> people;
    deque<ll> deque1, deque2;
    for(ll i = 0; i < N; i++){
        Person p; fin >> p.time_in >> p.duration >> p.type;
        people.push_back(p);
    }
    sort(people.begin(), people.end(), Compare);

    ll last_timestamp = 0;
//    ll last_timestamp2 = 0;
    ll num_fails = 0;
    ll num_processed = 0;

    for(ll i = 0; i < people.size(); i++){
        ll cur_timestamp = people[i].time_in;
        ll duration = people[i].duration;
        ll type = people[i].type;
        deque1 = update_deque(deque1, cur_timestamp, last_timestamp);
        deque2 = update_deque(deque2, cur_timestamp, last_timestamp);
        last_timestamp = cur_timestamp;
        if (type == 1){
            if(deque1.size() < 14) deque1.push_back(duration);
            else{num_fails++;}
        }
        else if (type == 2){
            if(deque2.size() < 14) {deque2.push_back(duration); num_processed++;}
            else{num_fails++;}
        }
        else{
            if (deque1.size() < deque2.size() && deque1.size() < 14){
                deque1.push_back(duration);
            }
            else if (deque2.size() < deque1.size() && deque2.size() < 14){
                deque2.push_back(duration);
                num_processed++;
            }
            else if (deque2.size() == deque1.size() && deque1.size() < 14){
                deque1.push_back(duration);
            }
            else{num_fails++;}
        }
    }
    cout << num_processed << " " << num_fails << endl;
    return 0;
}