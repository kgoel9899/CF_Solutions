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
		vector<int> v(n), temp;
		int mini = INT_MAX;
		map<int, int> m;
		map<int, vector<int>> tempm;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mini = min(mini, v[i]);
			m[v[i]]++;
		}
		for (int i = 0; i < n; i++) {
			if (v[i] % mini != 0) {
				temp.push_back(v[i]);
				tempm[v[i]].push_back(i);
			}
		}
		int flag = 0;
		for (int i = 1; i < (int)(temp.size()); i++) {
			if (temp[i] < temp[i - 1]) {
				flag = 1;
				break;
			}
		}
		int curr = 0;
		for (auto i : m) {
			vector<int> v = tempm[i.first];
			if (v.size() != 0) {
				// cout << i.first << endl;
				// cout << i.first << " " << curr << endl;
				if (v[0] != curr) {
					flag = 1;
					break;
				}
				for (int j = 1; j < (int)(v.size()); j++) {
					if (v[j] != v[j - 1] + 1) {
						flag = 1;
						break;
					}
				}
			}
			curr += i.second;
		}
		if (flag == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
