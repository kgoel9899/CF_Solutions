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
	vector<ll> pref, suff;
	pref.push_back(0);
	suff.push_back(0);
	ll a[n];
	map<ll, ll> m;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	for (ll i = 0; i < n - 1; i++) {
		pref.push_back(pref[i] + a[i]);
	}
	for (ll i = n - 1, j = 0; i > 0; i--, j++) {
		suff.push_back(suff[j] + a[i]);
	}
	reverse(suff.begin(), suff.end());
	vector<ll> ans;
	for (ll i = 0; i < n; i++) {
		ll curr = pref[i] + suff[i];
		if (curr % 2 == 1) continue;
		m[a[i]]--;
		if (m[curr / 2] > 0) ans.push_back(i + 1);
		m[a[i]]++;
	}
	cout << ans.size() << endl;
	for (ll i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}
