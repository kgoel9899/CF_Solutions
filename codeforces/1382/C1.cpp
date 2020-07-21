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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		if (a == b) cout << 0 << endl;
		else {
			vector<int> ans;
			for (int i = n - 1; i >= 0; i--) {
				if (a[i] == b[i]) continue;
				else {
					if (a[0] == b[i]) {
						a[0] = (a[0] == '0') ? '1' : '0';
						ans.push_back(1);
					}
					for (int j = 0; j <= i; j++) {
						a[j] = (a[j] == '0') ? '1' : '0';
					}
					ans.push_back(i + 1);
					int x = 0, y = i;
					while (x <= y) {
						swap(a[x++], a[y--]);
					}
				}
			}
			cout << ans.size() << " ";
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
