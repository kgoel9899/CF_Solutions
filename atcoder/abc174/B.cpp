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
		int n, d;
		cin >> n >> d;
		int ans = 0;
		while(n--) {
			int a, b;
			cin >> a >> b;
			double dist = pow(a * a + b * b, 0.5);
			if(dist <= d) ans++;
		}
		cout << ans << endl;
	}
}