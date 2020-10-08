#include<bits/stdc++.h>
using namespace std;
#define mx 1000010
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n), sieve(mx);
		for(int i=0;i<n;i++) {
			cin >> v[i];
			sieve[v[i]]++;
		}
		int ans = 0;
		for(int i=1;i<mx;i++) {
			if(sieve[i] != 0) {
				if(sieve[i] == 1) ans++;
				for(int j=2*i;j<mx;j+=i) {
					sieve[j] = 0;
				}
			}
		}
		cout << ans << endl;
	}
}