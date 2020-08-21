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
		vector<int> v(n), temp(n);
		int mini = INT_MAX;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			mini = min(mini, v[i]);
			temp[i] = v[i];
		}
		int flag = 0;
		sort(temp.begin(), temp.end());
		for (int i = 0; i < n; i++) {
			if (v[i] % mini != 0) {
				if (v[i] != temp[i]) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}