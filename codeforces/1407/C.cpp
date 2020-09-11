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
	// cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> ans(n);
		int mx = 0;
		for (int i = 1; i < n; i++) {
			cout << "? " << mx + 1 << " " << i + 1 << endl;
			cout.flush();
			int x, y;
			cin >> x;
			cout << "? " << i + 1 << " " << mx + 1 << endl;
			cout.flush();
			cin >> y;
			if (x > y) {
				ans[mx] = x;
				mx = i;
			} else ans[i] = y;
		}
		ans[mx] = n;
		cout << "! ";
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		cout.flush();
	}
}
