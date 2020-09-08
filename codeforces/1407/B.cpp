#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
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
		int mx = INT_MIN, ind = -1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (v[i] > mx) {
				mx = v[i];
				ind = i;
			}
		}
		vector<int> ans;
		ans.push_back(mx);
		set<int> s;
		s.insert(ind);
		int cgcd = mx;
		for (int i = 0; i < n - 1; i++) {
			mx = 0;
			ind = -1;
			for (int j = 0; j < n; j++) {
				if (s.count(j) > 0) continue;
				if (__gcd(cgcd, v[j]) > mx) {
					mx = __gcd(cgcd, v[j]);
					ind = j;
				}
			}
			s.insert(ind);
			ans.push_back(v[ind]);
			cgcd = mx;
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}
