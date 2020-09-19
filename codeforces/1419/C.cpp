#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--) {
		ll n, x;
		cin >> n >> x;
		vector<ll> v(n);
		ll sum = 0, ct = 0;
		for(ll i=0;i<n;i++) {
			cin >> v[i];
			sum += (x - v[i]);
			if(v[i] != x) ct++;
		}
		// cout << ct << endl;
		// if(ct != 0) {
		// 	if(sum == 0) cout << 1 << endl;
		// 	else cout << 2 << endl;
		// } else cout << 0 << endl;
		if(ct == 0) cout << 0 << endl;
		else {
			if(ct != n || sum == 0) cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
}