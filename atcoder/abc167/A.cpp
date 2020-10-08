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
		string s, t;
		cin >> s >> t;
		int n = s.size();
		if(s == t.substr(0, n)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}