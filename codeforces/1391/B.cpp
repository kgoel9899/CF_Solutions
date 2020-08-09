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
		int n, m;
		cin >> n >> m;
		int ct = 0;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (s[m - 1] == 'R') ct++;
			if (i == n - 1) {
				for (int j = 0; j < m; j++) {
					if (s[j] == 'D') ct++;
				}
			}
		}
		cout << ct << endl;
	}
}
