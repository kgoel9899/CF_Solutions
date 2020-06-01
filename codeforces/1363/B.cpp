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
		string s;
		cin >> s;
		int n = s.size();
		int ans1 = INT_MAX, ans2 = INT_MAX, temp1 = 0, temp2 = 0, ct1 = 0, ct2 = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && s[i - 1] == '1') temp1++;
			ct1 = 0;
			if (s[i] == '0') ct1++;
			for (int j = i + 1; j < n; j++) {
				if (s[j] == '0') ct1++;
			}
			ans1 = min(ans1, temp1 + ct1);
		}
		for (int i = 0; i < n; i++) {
			if (i > 0 && s[i - 1] == '0') temp2++;
			ct2 = 0;
			if (s[i] == '1') ct2++;
			for (int j = i + 1; j < n; j++) {
				if (s[j] == '1') ct2++;
			}
			ans2 = min(ans2, temp2 + ct2);
		}
		cout << min(ans1, ans2) << endl;
	}

	return 0;
}
