#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
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
		vector<int> v(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int prod = 1, mx = 1e18, flag = 0;
		for(int i=0;i<n;i++) {
			if(mx / prod < v[i]) {
				flag = 1;
				break;
			} else prod *= v[i];
			if(prod == 0) break;
		}
		if(flag == 1) cout << -1 << endl;
		else cout << prod << endl;
	}
}