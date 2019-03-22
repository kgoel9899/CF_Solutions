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
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll modRecursive(ll a, ll b, ll c){
    if(b == 0){
        return 1;
    }
    if(b % 2 ==0){
        return modRecursive((a * a) % c, b / 2, c);
    } else {
        return ((a % c) * (modRecursive((a * a) % c, b / 2, c))) % c;
    }
}
void dfs(ll start, vector<ll>* edges, ll n, set<ll>& visited, set<ll> * component) {
    visited.insert(start);
    component->insert(start);
    vector<ll>::iterator it = edges[start].begin();
    for(;it != edges[start].end(); it++) {
        ll i = *it;
        if (visited.count(i) > 0) {
            continue;
        }
        dfs(i, edges,n, visited, component);
    }
}
set<set<ll>*>* getComponents(vector<ll>* edges, ll n) {
    set<ll> visited;
    set<set<ll>*>* output = new set<set<ll>*>();
    for (ll i=0;i<n;i++) {
        if (visited.count(i) == 0) {
            set<ll> * component = new set<ll>();
            dfs(i, edges,n, visited, component);
            output->insert(component);
        }
    }
    return output;
}
int main() {
    IO;
    ll n, k;
    cin >> n >> k;
    ll ct = modRecursive(n, k, MOD);
    vector<ll>* edges = new vector<ll>[n];
    for (ll i=0;i<n-1;i++) {
        ll j, k, x;
        cin >> j >> k >> x;
        if(x == 0) {
            edges[j - 1].push_back(k - 1);
            edges[k - 1].push_back(j - 1);
        }
    }
    set<set<ll>*>* components = getComponents(edges, n);
    set<set<ll>*>::iterator it = components->begin();
    while (it != components->end()) {
        set<ll>* component = *it;
        ct -= modRecursive(component->size(), k, MOD);
        ct += MOD;
        ct %= MOD;
        delete component;
        it++;
    }
    delete components;
    delete [] edges;
    cout << ct << endl;
}
