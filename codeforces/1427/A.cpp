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
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		int sum = 0;
		for(int i=0;i<n;i++) {
			cin >> v[i];
			sum += v[i];
		}
		sort(v.begin(), v.end());
		if(sum == 0) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			if(sum > 0) reverse(v.begin(), v.end());
			for(int i=0;i<n;i++) {
				cout << v[i] << " ";
			}
			cout << endl;
		}
	}
}