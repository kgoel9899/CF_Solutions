#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
bool check(vector<int>& v, int n, int k, int mid) {
	int temp = 0;
	for(int i=0;i<n;i++) {
		temp += (v[i] - 1) / mid;
	}
	return temp <= k;
}
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		int mx = 0;
		for(int i=0;i<n;i++) {
			cin >> v[i];
			mx = max(mx, v[i]);
		}
		int beg = 1, end = mx, ans = mx;
		while(beg <= end) {
			int mid = (beg + end) / 2;
			if(check(v, n, k, mid)) {
				ans = mid;
				end = mid - 1;
			} else beg = mid + 1;
		}
		cout << ans << endl;
	}
}