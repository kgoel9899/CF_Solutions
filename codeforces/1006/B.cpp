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
		int n, k;
		cin >> n >> k;
		vector<pair<int, int>> v(n);
		for(int i=0;i<n;i++) {
			cin >> v[i].first;
			v[i].second = i;
		}
		sort(v.begin(), v.end(), greater<pair<int, int>>());
		// cout << v[0].first << " " << v[0].second << endl;
		vector<int> inds;
		int ans = 0;
		for(int i=0;i<k;i++) {
			inds.push_back(v[i].second);
			ans += v[i].first;
		}
		cout << ans << endl;
		sort(inds.begin(), inds.end());
		// for(int i=0;i<k;i++) {
		// 	cout << inds[i] << " ";
		// }
		// cout << endl;
		int last = -1;
		for(int i=0;i<k-1;i++) {
			cout << inds[i] - last << " ";
			last = inds[i];
		}
		cout << n - last - 1;
		cout << endl;
	}
}