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
	// cin >> t;	
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> v(n);
		for(ll i=0;i<n;i++) {
			cin >> v[i];
		}
		vector<ll> suff(n + 1);
		for(ll i=n-1;i>=0;i--) {
			suff[i] = suff[i + 1] + v[i];
		}
		ll ans = 0, sum = 0;
		for(ll i=0;i<n;i++) {
			sum += v[i];
			ll beg = i + 1, end = n - 1;
			while(beg <= end) {
				ll mid = (beg + end) / 2;
				if(suff[mid] > sum) beg = mid + 1;
				else if(suff[mid] < sum) end = mid - 1;
				else {
					ans = sum;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}