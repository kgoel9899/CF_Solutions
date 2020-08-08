#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 998244353
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
}
int main() {
	IO();
	int t = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		map<int, int> m;
		int maxi = -1, ct = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			m[v[i]]++;
			maxi = max(maxi, m[v[i]]);
		}
		for (auto i : m) {
			if (i.second == maxi) ct++;
		}
		int temp = n - ct * maxi;
		// if (ct == 2) cout << temp << endl;
		// cout << temp << " " << maxi << endl;
		cout << temp / (maxi - 1) + ct - 1 << endl;
	}
}
