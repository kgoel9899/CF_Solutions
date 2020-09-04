#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast;
}
int main() {
	IO();
	ll t = 1;
	cin >> t;
	while (t--) {
		ll n, s;
		cin >> n >> s;
		ll temp = n, sum = 0;
		string st = "";
		while (temp) {
			sum += temp % 10;
			st += temp % 10 + '0';
			temp /= 10;
		}
		if (sum <= s) cout << 0 << endl;
		else {
			reverse(st.begin(), st.end());
			ll curr = 0, i = 0, lastnum = 0;
			for (; i < (ll)st.size(); i++) {
				curr += st[i] - '0';
				if (curr > s) {
					curr -= st[i] - '0';
					break;
				}
				if (st[i] != '0') lastnum = i;
			}
			if (i == 0) cout << (ll)pow(10, (ll)st.size()) - n << endl;
			else {
				ll save = i;
				if (curr == s) {
					i = lastnum;
					st[i] = '0';
				}
				i--;
				while (i >= 0 && st[i] == '9') {
					st[i] = '0';
					i--;
				}
				if (i == -1) st.insert(0, "1");
				else st[i]++;
				for (ll i = save; i < (ll)st.size(); i++) {
					st[i] = '0';
				}
				ll num1 = 0, ten = 1;
				for (ll i = (ll)st.size() - 1; i > 0; i--) {
					num1 += ten * (st[i] - '0');
					ten *= 10;
				}
				num1 += ten * (st[0] - '0');
				cout << num1 - n << endl;
			}
		}
	}
}
