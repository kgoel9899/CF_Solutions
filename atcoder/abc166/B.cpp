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
		int n, k;
		cin >> n >> k;
		set<int> s;
		for(int i=0;i<k;i++) {
			int x;
			cin >> x;
			while(x--) {
				int num;
				cin >> num;
				s.insert(num);
			}
		}
		cout << n - s.size() << endl;
	}
}