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
bool check(ll* arr, ll days, ll n, ll m) {
    ll checksum = 0, temp = 0;
    for(ll i=0;i<n;i++) {
        checksum += max((ll)0, arr[i] - temp);
        if((i + 1) % days == 0) {
            temp++;
        }
    }
    if(checksum >= m) {
        return true;
    }
    return false;
}
int main() {
    fast;
    ll n, m;
    cin >> n >> m;
    ll* arr = new ll[n];
    for(ll i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<ll>());
    ll beg = 1, last = n, ans = n, flag = 0;
    while(beg <= last) {
        ll mid = (last + beg) / 2;
        if(check(arr, mid, n, m) == true) {
            flag = 1;
            last = mid - 1;
            ans = min(ans, mid);
        } else {
            beg = mid + 1;
        }
    }
    if(flag == 1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}