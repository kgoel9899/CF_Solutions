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
		int x, y;
		cin >> x >> y;
		int flag = 0;
		for(int i=0;i<=min(x, y / 2);i++) {
			if(i * 2 + (x - i) * 4 == y) {
				flag = 1;
				break;
			}
		}
		if(flag == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}