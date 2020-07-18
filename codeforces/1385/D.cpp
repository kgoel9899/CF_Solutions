#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
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

int helper(string& s, int l, int r, char c) {
	if (l + 1 == r) {
		if (s[l] == c) return 0;
		else return 1;
	}
	int ct1 = 0, ct2 = 0;
	int mid = (l + r) / 2;
	for (int i = l; i < mid; i++) {
		if (s[i] != c) ct1++;
	}
	for (int i = mid; i < r; i++) {
		if (s[i] != c) ct2++;
	}
	int left = helper(s, l, mid, (char)(c + 1));
	int right = helper(s, mid, r, (char)(c + 1));
	return min(ct2 + left, ct1 + right);
}

int main() {

	IO();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		cout << helper(s, 0, n, 'a') << endl;
	}

	return 0;
}
