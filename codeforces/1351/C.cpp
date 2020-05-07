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

map<pair<int, int>, vector<pair<int, int>>> m;

bool check(int x, int y, int nx, int ny) {
	for (int i = 0; i < m[make_pair(x, y)].size(); i++) {
		if (m[make_pair(x, y)][i] == make_pair(nx, ny)) return true;
	}
	return false;
}

int main() {

	IO();

	int t;
	cin >> t;
	while (t--) {
		m.clear();
		string s;
		cin >> s;
		int x = 0, y = 0;
		int nx, ny;
		int ct = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'N') {
				nx = x;
				ny = y + 1;
			} else if (s[i] == 'S') {
				nx = x;
				ny = y - 1;
			} else if (s[i] == 'E') {
				nx = x + 1;
				ny = y;
			} else {
				nx = x - 1;
				ny = y;
			}
			if (check(x, y, nx, ny)) ct++;
			else {
				m[make_pair(x, y)].push_back(make_pair(nx, ny));
				m[make_pair(nx, ny)].push_back(make_pair(x, y));
				ct += 5;
			}
			x = nx;
			y = ny;
		}
		cout << ct << endl;
	}

	return 0;
}
