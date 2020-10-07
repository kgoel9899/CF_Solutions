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
		int s;
		cin >> s;
		vector<int> v(s + 1);
		v[0] = 1;
		for(int i=3;i<=s;i++) {
			v[i] = v[i - 1] + v[i - 3];
			v[i] %= MOD;
		}
		cout << v[s] << endl;
	}
}