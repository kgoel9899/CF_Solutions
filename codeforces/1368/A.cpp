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

	int t;
	cin >> t;
	while (t--) {
		ll a, b, n;
		cin >> a >> b >> n;
		ll ta = a, tb = b;
		ll ct1 = INT_MAX, ct2 = INT_MAX;
		// while (ta <= n) {
		// 	ta += b;
		// 	ct1++;
		// }
		// while (tb <= n) {
		// 	tb += a;
		// 	ct2++;
		// }
		ta = a;
		tb = b;
		ll ct3 = 0, x = 0;
		while (ta <= n && tb <= n) {
			if (x % 2 == 0) ta += tb;
			else tb += ta;
			ct3++;
			x++;
		}
		ll ct4 = 0;
		x = 0;
		ta = a;
		tb = b;
		while (ta <= n && tb <= n) {
			if (x % 2 == 0) tb += ta;
			else ta += tb;
			ct4++;
			x++;
		}
		cout << min(ct1, min(ct2, min(ct3, ct4))) << endl;
	}

	return 0;
}
