#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#define ll long long
#define MAX 8200
#define MOD 1000000007
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    ll y = 0, x = 0;
    ll i = 0;
    for(;i<n/2;i++) {
        y += arr[i];
    }
    for(;i<n;i++) {
        x += arr[i];
    }
    ll ans = x * x + y * y;
    cout << ans << endl;
}