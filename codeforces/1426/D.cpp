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
		int n;
		cin >> n;
		vector<int> v(n);
		set<int> s;
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		s.insert(0);
		int curr = 0, ans = 0;
		for(int i=0;i<n;i++) {
			curr += v[i];
			if(s.count(curr) > 0) {
				ans++;
				s.clear();
				s.insert(0);
				curr = v[i];
			}
			s.insert(curr);
		}
		cout << ans << endl;
	}
}