#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int modexpo(int a, int b, int c = MOD){
	if(b == 0) return 1;
	if(b % 2 == 0) return modexpo((a * a) % c, b / 2, c);
	else return ((a % c) * (modexpo((a * a) % c, b / 2, c))) % c;
}
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans = modexpo(10, n) - modexpo(9, n);
		ans += MOD;
		ans %= MOD;
		ans -= modexpo(9, n);
		ans += MOD;
		ans %= MOD;
		ans += modexpo(8, n);
		ans %= MOD;
		cout << ans << endl;
	}
}