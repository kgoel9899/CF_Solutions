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
		vector<int> v(n);
		int maxi = 1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			maxi = max(maxi, v[i]);
		}
		string s = "";
		for (int i = 0; i < maxi; i++) {
			s += 'a';
		}
		cout << s << endl;
		for (int i = 0; i < n; i++) {
			if (s[v[i]] == 'a') s[v[i]] = 'b';
			else s[v[i]] = 'a';
			// s[v[i]] = (char)(s[v[i]] + 1);
			// if (s[v[i]] == '{') s[v[i]] = 'a';
			cout << s << endl;
		}
	}
}
