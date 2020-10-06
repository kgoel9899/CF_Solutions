#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
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
		string s;
		cin >> s;
		int ans = 0, ct = 0;
		for(int i=0;i<3;i++) {
			if(s[i] == 'R') ct++;
			else {
				ans = max(ans, ct);
				ct = 0;
			}
		}
		ans = max(ans, ct);
		cout << ans << endl;
	}
}