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
		int n;
		cin >> n;
		vector<vector<int>> v(n, vector<int>(n));
		vector<int> all(n, 1);
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				int num;
				cin >> num;
				if(num == 1) all[i] = 0; 
				else if(num == 2) all[j] = 0;
				else if(num == 3) {
					all[i] = 0;
					all[j] = 0;
				}
			}
		}
		int ans = 0;
		for(int i=0;i<n;i++) {
			if(all[i] == 1) ans++;
		}
		cout << ans << endl;
		for(int i=0;i<n;i++) {
			if(all[i] == 1) cout << i + 1 << " ";
		}
		cout << endl;
	}
}