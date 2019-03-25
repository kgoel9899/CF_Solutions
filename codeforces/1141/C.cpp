#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#include<unordered_set>
#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    fast;
    ll n;
    set<ll> s;
    cin >> n;
    ll q[n - 1], p[n];
    for(ll i=0;i<n;i++) {
        p[i] = 0;
    }
    ll mini = INT_MAX, flag = 0;
    for(ll i=0;i<n-1;i++) {
        cin >> q[i];
        p[i + 1] = p[i] + q[i];
    }
    for(ll i=0;i<n;i++) {
        mini = min(mini, p[i]);
    }
    ll x = 1 - mini;
    for(ll i=0;i<n;i++) {
        p[i] += x;
        s.insert(p[i]);
    }
    for(ll i=0;i<n;i++) {
        if(p[i] < 1 || p[i] > n) {
            flag = 1;
            break;
        }
    }
    for(ll i=1;i<=n;i++) {
        if(s.count(i) == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        cout << -1 << endl;
    } else {
        for(ll i=0;i<n;i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
}

