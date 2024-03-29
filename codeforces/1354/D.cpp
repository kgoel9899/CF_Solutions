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
#define MAX 1000010
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

int BIT[MAX];
void update(int i, int add) {
	while (i > 0 && i < MAX) {
		BIT[i] += add;
		i += (i & (-i));
	}
}

int getSum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += BIT[i];
		i = i - (i & (-i));
	}
	return ans;
}

int main() {

	IO();

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		update(v[i], 1);
	}
	while (q--) {
		int k;
		cin >> k;
		if (k > 0) update(k, 1);
		else {
			k = abs(k);
			int beg = 0, end = MAX;
			while (beg < end) {
				int mid = (beg + end) / 2, temp = getSum(mid);
				if (k <= temp) end = mid;
				else beg = mid + 1;
			}
			update(beg, -1);
		}
	}
	int ans = getSum(MAX);
	if (ans == 0) cout << 0 << endl;
	else {
		int beg = 0, end = MAX;
		while (beg < end) {
			int mid = (beg + end) / 2, temp = getSum(mid);
			if (ans <= temp) end = mid;
			else beg = mid + 1;
		}
		cout << beg << endl;
	}

	return 0;
}
