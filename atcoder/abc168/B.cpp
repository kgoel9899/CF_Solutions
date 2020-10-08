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
		int k;
		cin >> k;
		string s;
		cin >> s;
		int n = s.size();
		if(n <= k) cout << s << endl;
		else cout << s.substr(0, k) + "..." << endl;
	}
}