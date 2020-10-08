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
		vector<int> v(5);
		for(int i=0;i<5;i++) {
			cin >> v[i];
		}
		for(int i=0;i<5;i++) {
			if(v[i] == 0) cout << i + 1 << endl;
		}
	}
}