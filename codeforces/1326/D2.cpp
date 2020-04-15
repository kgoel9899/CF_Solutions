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

int helper(string s) {
	string temp = s;
	reverse(temp.begin(), temp.end());
	s = s + "#" + temp;
	int n = s.size();
	int lps[n];
	lps[0] = 0;
	int len = 0, i = 1;
	while (i < n) {
		if (s[len] == s[i]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if (len != 0) len = lps[len - 1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps[n - 1];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		int len = 0, i = 0, j = n - 1;
		for (; i<n, j >= 0, i < j; i++, j--) {
			if (s[i] == s[j]) len++;
			else break;
		}
		string ans = s.substr(0, len);
		string temp = s.substr(len, n - 2 * len);
		int ct1 = helper(temp);
		string tempr = temp;
		reverse(tempr.begin(), tempr.end());
		int ct2 = helper(tempr);
		if (ct1 >= ct2) ans += temp.substr(0, ct1);
		else ans += tempr.substr(0, ct2);
		ans += s.substr(n - len);
		cout << ans << endl;
	}

	return 0;
}
