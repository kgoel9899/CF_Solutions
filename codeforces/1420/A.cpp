#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
ll merge(vector<ll>& a, ll left, ll mid, ll right) {
    ll i = left, j = mid, k = 0;
    ll temp[right - left + 1];
    ll ct = 0;
    while(i < mid && j <= right) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            ct += mid - i;
        }
    }
    while(i < mid) {
        temp[k++] = a[i++];
    }
    while(j <= right) {
        temp[k++] = a[j++];
    }
    for(ll i=left,k=0;i<=right;i++,k++) {
        a[i] = temp[k];
    }
    return ct;
}
ll mergesort(vector<ll>& a, ll left, ll right) {
    if(right > left) {
        ll mid = (left + right) / 2;
		return mergesort(a, left, mid) + mergesort(a, mid + 1, right) + merge(a, left, mid + 1, right);
    }
    return 0;
}
int main() {
	fast;
	ll t = 1;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> v(n);
		for(ll i=0;i<n;i++) {
			cin >> v[i];
		}
		ll ans = mergesort(v, 0, n - 1);
		if(ans <= (n * (n - 1)) / 2 - 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}