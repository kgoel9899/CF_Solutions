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
		string s, t;
		cin >> s >> t;
		int n = s.size(), ct = 0;
		for(int i=0;i<n;i++) {
			ct += s[i] != t[i];
		}
		if(ct % 2 != 0) cout << "impossible" << endl;
		else {
			string ans = s;
			ct /= 2;
			for(int i=0;i<n;i++) {
				if(ans[i] != t[i]) {
					if(ans[i] == '1') ans[i] = '0';
					else ans[i] = '1';
					ct--;
				}
				if(ct == 0) break;
			}
			cout << ans << endl;
		}
	}
}