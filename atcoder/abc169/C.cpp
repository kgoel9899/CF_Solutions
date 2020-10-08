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
		int a;
		cin >> a;
		string s;
		cin >> s;
		int b = (s[0] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
		int ans = a * b;
		cout << ans / 100 << endl;
	}
}