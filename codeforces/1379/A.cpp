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

int main() {

	IO();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string giv = "abacaba";
		int ct = 0;
		for (int i = 0; i <= n - 7; i++) {
			string temp = "";
			for (int j = i; j < i + 7; j++) {
				temp += s[j];
			}
			if (temp == giv) ct++;
		}
		if (ct == 1) {
			cout << "YES" << endl;
			for (int aa = 0; aa < n; aa++) {
				if (s[aa] == '?') s[aa] = 'z';
			}
			cout << s << endl;
		} else if (ct >= 2) cout << "NO" << endl;
		else {
			int i = 0;
			for (; i <= n - 7; i++) {
				string temp = "";
				for (int j = i; j < i + 7; j++) {
					temp += s[j];
				}

				int j = 0;
				for (; j < 7; j++) {
					if (temp[j] == '?' || temp[j] == giv[j]) {
						continue;
					} else {
						break;
					}
				}
				string ns = s;
				if (j == 7) {
					int x = 0;
					for (int k = i; k < i + 7; k++) {
						ns[k] = giv[x++];
					}
				}

				int ct1 = 0;
				for (int l = 0; l <= n - 7; l++) {
					string temp = "";
					for (int m = l; m < l + 7; m++) {
						temp += ns[m];
					}
					if (temp == giv) ct1++;
				}
				if (ct1 == 1) {
					cout << "YES" << endl;
					for (int aa = 0; aa < n; aa++) {
						if (ns[aa] == '?') ns[aa] = 'z';
					}
					cout << ns << endl;
					break;
				}
			}
			if (i == n - 6) cout << "NO" << endl;
		}
	}

	return 0;
}
