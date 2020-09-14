#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
	fast;
	int t = 1;
	cin >> t;
    while(t--) {
		ll x, y, k;
		cin >> x >> y >> k;
		ll curr = 1;
		ll ans = 0;
		curr -= y * k;
		ans += k;
		// cout << ans << endl;
		ll temp = k - curr;
		ans += temp / (x - 1);
		if(temp % (x - 1) != 0) ans++;
		cout << ans << endl;
    }
}
