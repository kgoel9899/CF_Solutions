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
		int n, m;
		cin >> n >> m;
		vector<int> v(n), p(m);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		set<int> s;
		for (int i = 0; i < m; i++) {
			cin >> p[i];
			p[i]--;
			s.insert(p[i]);
		}
		vector<int> temp(n);
		temp = v;
		sort(temp.begin(), temp.end());
		int x = 0;
		int curr = temp[x];
		int flag = 0;
		while (true) {
			int ind = -1;
			// if (x == n - 1) {
			// 	// for (int i = 0; i < n; i++) {
			// 	// 	cout << v[i] << " ";
			// 	// }
			// 	// cout << endl;
			// 	break;
			// }
			for (int i = x; i < n; i++) {
				if (v[i] == curr) {
					ind = i;
					break;
				}
			}
			// cout << curr << endl;
			// cout << ind << endl;
			// x++;
			// curr = temp[x];
			// cout << curr << endl;
			if (ind == x) {
				if (ind == n - 1) break;
				x++;
				curr = temp[x];
				continue;
			}
			while (ind > x) {
				if (s.count(ind - 1) == 0) {
					flag = 1;
					break;
				}
				swap(v[ind - 1], v[ind]);
				ind--;
			}
			if (flag == 1) break;
			if (ind == x) {
				x++;
				curr = temp[x];
				continue;
			}
			while (ind < x) {
				if (s.count(ind) == 0) {
					flag = 1;
					break;
				}
				swap(v[ind], v[ind + 1]);
				ind++;
			}
			if (ind == x) {
				x++;
				curr = temp[x];
				continue;
			} else {
				flag = 1;
				break;
			}
			x++;
			curr = temp[x];
		}
		if (flag == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
