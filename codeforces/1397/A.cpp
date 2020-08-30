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
		map<char, int> m;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < (int)s.size(); j++) {
				m[s[j]]++;
			}
		}
		int flag = 0;
		for (auto i : m) {
			if (i.second % n != 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
