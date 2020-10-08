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
		vector<int> sieve(mx, 1);
		sieve[0] = 0, sieve[1] = 0;
		for(int i=2;i*i<=mx;i++) {
			for(int j=i*i;j<mx;j+=i) {
				sieve[j] = 0;
			}
		}
		int ans = 0;
		map<int, int> m;
		for(int i=2;i<mx;i++) {
			if(sieve[i] == 1) {
				int curr = 1;
				while(n % i == 0) {
					m[i]++;
					n /= i;
				}
			}
		}
		if(n != 1) m[n]++;
		for(auto i : m) {
			int curr = 1, tot = i.second;
			while(curr <= tot) {
				ans++;
				tot -= curr;
				curr++;
			}
		}
		cout << ans << endl;
	}
}