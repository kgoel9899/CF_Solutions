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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n + 1), b(m + 1);
		for(int i=1;i<=n;i++) {
			int num;
			cin >> num;
			a[i] = a[i - 1] + num;
		}
		for(int i=1;i<=m;i++) {
			int num;
			cin >> num;
			b[i] = b[i - 1] + num;
		}
		int ans = 0;
		for(int i=0;i<=n;i++) {
			int x = i, y = 0;
			int beg = 0, end = m;
			while(beg <= end) {
				int mid = (beg + end) / 2;
				if(b[mid] > k - a[i]) end = mid - 1;
				else {
					y = mid;
					beg = mid + 1;
				}
			}
			if(k >= a[x] + b[y]) ans = max(ans, x + y);
		}
		cout << ans << endl;
	}
}