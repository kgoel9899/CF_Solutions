#include<bits/stdc++.h>
#include<iostream>
#define ll long long
#define MAX 8200
#define MOD 1000000007
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    queue<int> q;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    map<ll, ll> m;
    vector<ll> v;
    ll ct = 0;
    ll temp = -1;
    for(int i=0;i<n;i++) {
        if(m[arr[i]] != 1) {
            if(ct >= k) {
                temp = q.front();
                m[temp] = 0;
                q.pop();
            } else {
                ct++;
            }
            q.push(arr[i]);
            m[arr[i]] = 1;
        }
    }
    cout << q.size() << endl;
    while(!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }
    for(ll i=(ll)v.size()-1;i>=0;i--) {
        cout << v[i] << " ";
    }
    cout << endl;
}

