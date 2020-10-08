#include<bits/stdc++.h>
using namespace std;
#define MAX 1000010
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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		while(true) {
			c -= b;
			if(c <= 0) {
				cout << "Yes" << endl;
				break;
			}
			a -= d;
			if(a <= 0) {
				cout << "No" << endl;
				break;
			}
		}
	}
}