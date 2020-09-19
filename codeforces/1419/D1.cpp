#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
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
		sort(v.begin(), v.end());
		int ans = (n - 1) / 2;
		vector<int> nv(n);
		int x = 0;
		for(int i=1;i<n;i+=2) {
			nv[i] = v[x++];
		}
		for(int i=0;i<n;i+=2) {
			nv[i] = v[x++];
		}
		cout << ans << endl;
		for(int i=0;i<n;i++) {
			cout << nv[i] << " ";
		}
		cout << endl;
	}
}