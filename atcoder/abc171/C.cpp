#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
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
		string ans = "";
		while(n) {
			int temp = n % 26;
			if(temp == 0) n--;
			n /= 26;
			if(temp == 0) ans += 'z';
			else ans += char('a' + temp - 1);
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}