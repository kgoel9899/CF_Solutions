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
		unordered_map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			m[v[i]]++;
		}
		int ans = 0;
		for (int i = 2; i < 105; i++) {
			int temp = 0, sum = i;
			unordered_map<int, int> m1 = m;
			for (int k = 0; k < n; k++) {
				if (m1[v[k]] > 0 && m1[sum - v[k]] > 0) {
					if (sum - v[k] == v[k]) {
						if (m1[v[k]] >= 2) {
							temp++;
							m1[v[k]] -= 2;
						}
					} else {
						m1[sum - v[k]]--;
						m1[v[k]]--;
						temp++;
					}
				}
			}
			ans = max(ans, temp);
		}
		cout << ans << endl;
	}
}
