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
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		int ans = 0;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				for(int k=j+1;k<n;k++) {
					int a = v[i], b = v[j], c = v[k];
					if(a + b > c && b + c > a && c + a > b && a != b && b != c && c != a) ans++;
				}
			}
		}
		cout << ans << endl;
	}
}