#include<bits/stdc++.h>
using namespace std;
#define MAX 1000010
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
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		map<int, int> m1, m2;
		vector<int> dp1(n), dp2(n);
		m1[v[0]]++;
		dp1[0] = 0;
		for(int i=1;i<n-1;i++) {
			if(v[i] % k == 0 && m1.find(v[i] / k) != m1.end()) dp1[i] = m1[v[i] / k];
			m1[v[i]]++;
		}
		dp2[n - 1] = 0;
		m2[v[n - 1]]++;
		for(int i=n-2;i>=0;i--) {
			if(m2.find(v[i] * k) != m2.end()) dp2[i] = m2[v[i] * k];
			m2[v[i]]++;
		}
		int ans = 0;
		for(int i=1;i<n-1;i++) {
			ans += dp1[i] * dp2[i];
		}
		cout << ans << endl;
	}
}