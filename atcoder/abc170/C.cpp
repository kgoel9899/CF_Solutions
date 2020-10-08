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
		int x, n;
		cin >> x >> n;
		set<int> s;
		for(int i=0;i<n;i++) {
			int num;
			cin >> num;
			s.insert(num);
		}
		int mn = INT_MAX, ans = x;
		for(int i=0;i<=105;i++) {
			if(abs(x - i) < mn && s.count(i) == 0) {
				mn = abs(x - i);
				ans = i;
			}
		}
		cout << ans << endl;
	}
}