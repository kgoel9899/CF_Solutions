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
		map<int, int> m;
		int zer = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			m[v[i]]++;
			if (v[i] == 0) zer = 1;
		}
		if (zer == 0) cout << 0 << endl;
		else {
			int ans = 0;
			int flag = 0;
			int curr = 0;
			for (auto i : m) {
				if (i.first == curr && i.second > 0) {
					m[curr]--;
				} else {
					ans += curr;
					flag = 1;
					break;
				}
				curr++;
			}
			if (flag == 0) ans += curr;
			curr = 0;
			flag = 0;
			for (auto i : m) {
				if (i.first == curr && i.second > 0) {
					m[curr]--;
				} else {
					ans += curr;
					flag = 1;
					break;
				}
				curr++;
			}
			if (flag == 0) ans += curr;
			cout << ans << endl;
		}
	}
}