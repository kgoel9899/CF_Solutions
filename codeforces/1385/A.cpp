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
		int x, y, z;
		cin >> x >> y >> z;
		swap(y, z);
		int a = min(x, z), b = min(x, y), c = min(y, z);
		if (x == max(a, b) && y == max(b, c) && z == max(c, a)) {
			cout << "YES" << endl;
			cout << a << " " << b << " " << c << endl;
		} else cout << "NO" << endl;
	}

	return 0;
}
