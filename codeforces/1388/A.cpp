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
		int a = 6, b = 10, c = 14;
		int diff = n - a - b - c;
		if (diff == a || diff == b || diff == c) c = 15;
		diff = n - a - b - c;
		if (diff > 0) {
			cout << "YES" << endl;
			cout << a << " " << b << " " << c << " " << diff << endl;
		} else cout << "NO" << endl;
	}
}
