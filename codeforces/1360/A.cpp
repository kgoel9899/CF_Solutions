#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define w(x) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define repd(i, b, a) for(int i = b; i >= a; i--)
#define mk(arr,n,type) type* arr = new type[n];
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define um unordered_map
#define us unordered_set
#define pqm priority_queue<int>
#define pqmi priority_queue<int, vi, greater<int>>
#define lb(v, val) lower_bound(v.begin(), v.end(), val) - v.begin();
#define ub(v, val) upper_bound(v.begin(), v.end(), val) - v.begin();
#define setbits(x) __builtin_popcountll(x)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define out(flag) flag ? cout << "NO" << endl : cout << "YES" << endl;
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

	ll t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		ll temp = a;
		a = max(a, b);
		b = min(temp, b);
		ll diff = 2 * b - a;
		if (diff < 0) cout << a * a << endl;
		else cout << (a + diff) * (a + diff) << endl;
		// if (a == b) {
		// 	cout << 4 * a * a << endl;
		// 	continue;
		// }
		// if (b * 2 == a) cout << a * a << endl;
		// else if (b * 2 > a) cout << (a + 1) * (a + 1) << endl;
		// else cout << a * a << endl;
	}

	return 0;
}
