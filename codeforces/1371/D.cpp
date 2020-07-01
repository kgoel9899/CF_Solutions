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
		int n, k;
		cin >> n >> k;
		vector<vector<int>> v(n, vector<int>(n));
		int a = INT_MIN, b = INT_MAX, c = INT_MIN, d = INT_MAX;
		int row = 0, col = 0, x = 0;
		int temp = k;
		int flag = 1;
		while (temp) {
			v[row][col] = 1;
			row++;
			col++;
			temp--;
			if (row == n && col == n) break;
		}
		row = 1, col = 0;
		x = 1;
		int y = n - 1;
		while (temp) {
			v[row][col] = 1;
			temp--;
			row++;
			col++;
			if (flag == 1) {
				if (row == n && col == n - x) {
					x++;
					col = y;
					row = 0;
					flag = 0;
				}
			}
			if (flag == 0) {
				if (row == n - y && col == n) {
					y--;
					col = 0;
					row = x;
					flag = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			int curr = 0;
			for (int j = 0; j < n; j++) {
				curr += v[i][j];
			}
			a = max(a, curr);
			b = min(b, curr);
		}
		for (int i = 0; i < n; i++) {
			int curr = 0;
			for (int j = 0; j < n; j++) {
				curr += v[j][i];
			}
			c = max(c, curr);
			d = min(d, curr);
		}
		cout << (a - b) * (a - b) + (c - d) * (c - d) << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << v[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
