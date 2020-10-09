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
		vector<int> cnt(mx);
		for(int i=0;i<n;i++) {
			int num;
			cin >> num;
			cnt[num]++;
		}
		vector<int> dp(mx);
		dp[1] = cnt[1];
		for(int i=2;i<mx;i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
		}
		cout << dp[mx - 1] << endl;
	}
}