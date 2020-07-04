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
		ll n, m;
		cin >> n >> m;
		vector<vector<ll>> v(n, vector<ll>(m));
		int flag = 0;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				cin >> v[i][j];
				if (v[i][j] > 4) flag = 1;
				if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
					if (v[i][j] > 2) flag = 1;
					v[i][j] = 2;
				} else if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					if (v[i][j] > 3) flag = 1;
					v[i][j] = 3;
				} else v[i][j] = 4;
			}
		}
		if (flag == 1) cout << "NO" << endl;
		else {
			// vector<pair<int, int>> v = m[4];
			// if(v.size() > 0) {
			// 	for(int i=0;i<v.size();i++) {
			// 		int x = v[i].first;
			// 		int y = v[i].second;
			// 		if(x == 0 || x == n - 1 || y == 0 || y == m - 1) {
			// 			flag = 1;
			// 			break;
			// 		} else {
			// 			if(v[x + 1][y] == 0) v[x + 1][y] = 1;
			// 			if(v[x - 1][y] == 0) v[x - 1][y] = 1;
			// 			if(v[x][y - 1] == 0) v[x][y - 1] = 1;
			// 			if(v[x][y + 1] == 0) v[x][y + 1] = 1;
			// 		}
			// 	}
			// }
			// v = m[3];
			// if(v.size() > 0) {
			// 	for(int i=0;i<v.size();i++) {
			// 		int x = v[i].first;
			// 		int y = v[i].second;
			// 		if((x == 0 && y == 0) || (x == 0 && y == m - 1) || (x == n - 1 && y == 0) || (x == n - 1 && y == m - 1)) {
			// 			flag = 1;
			// 			break;
			// 		} else {

			// 		}
			// 	}
			// }
			cout << "YES" << endl;
			for (ll i = 0; i < n; i++) {
				for (ll j = 0; j < m; j++) {
					cout << v[i][j] << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}
