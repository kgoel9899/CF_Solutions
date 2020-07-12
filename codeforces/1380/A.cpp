#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MAX 100001
#define mod 998244353
#define inf 1e18
#define PI 3.1415926535

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
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int a = 0, b = 0, c = 0;
		for (int i = 1; i < n; i++) {
			if (a != 0 && v[i] < v[b - 1]) {
				c = i + 1;
				break;
			}
			if (a == 0 && v[i] > v[i - 1]) {
				a = i;
				b = i + 1;
			}
			if (a != 0 && v[b - 1] < v[i]) b = i + 1;
		}
		if (c == 0) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			cout << a << " " << b << " " << c << endl;
		}
	}

	return 0;
}
