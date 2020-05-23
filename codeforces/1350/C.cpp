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

	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<ll> gcds(n);
	gcds[n - 1] = v[n - 1];
	for (ll i = n - 2; i >= 0; i--) {
		gcds[i] = __gcd(v[i], gcds[i + 1]);
	}
	vector<ll> ngcd;
	for (ll i = 1; i < n; i++) {
		ngcd.push_back((v[i - 1] * gcds[i]) / __gcd(v[i - 1], gcds[i]));
	}
	ll ans = ngcd[0];
	for (ll i = 1; i < ngcd.size(); i++) {
		ans = __gcd(ans, ngcd[i]);
	}
	cout << ans << endl;

	return 0;
}
