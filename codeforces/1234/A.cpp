#include<bits/stdc++.h>
#include<iostream>
#define ll long long
#define MAX 8200
#define MOD 1000000007
using namespace std;

int main() {
    ll q;
    cin >> q;
    while(q--) {
        ll n;
        cin >> n;
        ll arr[n];
        ll summ = 0;
        for(ll i=0;i<n;i++) {
            cin >> arr[i];
            summ += arr[i];
        }
        sort(arr, arr + n);
        ll beg = arr[0];
        ll end = arr[n - 1];
        ll ans = -1;
        while(beg <= end) {
            ll mid = (beg + end) / 2;
            if(mid * n >= summ) {
                end = mid - 1;
                ans = mid;
            } else {
                beg = mid + 1;
            }
        }
        cout << ans << endl;
    }
}