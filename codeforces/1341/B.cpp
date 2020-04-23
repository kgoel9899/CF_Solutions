#include<bits/stdc++.h>
using namespace std;

int main() {

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		map<int, vector<int>> m;
		vector<int> vis(n, 0);
		int maxi = INT_MIN;
		int ct = 0;
		for (int i = 1; i < k - 1; i++) {
			if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
				ct++;
				vis[i] = 1;
			}
		}
		maxi = max(maxi, ct);
		if (m[ct].size() == 0) {
			m[ct].push_back(1);
		}
		int curr = k - 1;
		for (int i = 2; curr < n - 1; i++) {
			if (vis[i - 1] == 1) {
				ct--;
			}
			if (v[curr] > v[curr - 1] && v[curr] > v[curr + 1]) {
				vis[curr] = 1;
				ct++;
			}
			if (m[ct].size() == 0) m[ct].push_back(i);
			maxi = max(maxi, ct);
			curr++;
		}
		cout << maxi + 1 << " " << m[maxi][0] << endl;
	}

	return 0;
}
