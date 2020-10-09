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
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> pref(n + 1);
		map<int, int> m;
		m[0]++;
		for(int i=1;i<=n;i++) {
			pref[i] = pref[i - 1] + (s[i - 1] - '0');
			m[pref[i] - i]++;
		}
		int ans = 0;
		for(auto i : m) {
			ans += ((i.second) * (i.second - 1)) / 2;
		}
		cout << ans << endl;
	}
}