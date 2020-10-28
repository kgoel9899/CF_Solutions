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
		int n, m;
		cin >> n >> m;
		vector<int> pre(n + 1);
		for(int i=1;i<=n;i++) {
			int num;
			cin >> num;
			pre[i] = pre[i - 1] + num;
		}
		for(int i=0;i<m;i++) {
			int a;
			cin >> a;
			int ind = lower_bound(pre.begin(), pre.end(), a) - pre.begin();
			cout << ind << " " << a - pre[ind - 1] << endl;
		}
	}
}