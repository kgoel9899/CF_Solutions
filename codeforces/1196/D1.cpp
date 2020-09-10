#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
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
	int t = 1;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int ans = INT_MAX;
		string temp = "";
		for (int i = 0; i < k / 3; i++) {
			temp += "RGB";
		}
		if (k % 3 == 1) temp += "R";
		else temp += "RG";
		for (int i = 0; i <= n - k; i++) {
			int curr = 0, x = 0;
			for (int j = i; j < i + k; j++) {
				if (s[j] != temp[x]) curr++;
				x++;
			}
			ans = min(ans, curr);
		}
		temp = "";
		for (int i = 0; i < k / 3; i++) {
			temp += "GBR";
		}
		if (k % 3 == 1) temp += "G";
		else temp += "GB";
		for (int i = 0; i <= n - k; i++) {
			int curr = 0, x = 0;
			for (int j = i; j < i + k; j++) {
				if (s[j] != temp[x]) curr++;
				x++;
			}
			ans = min(ans, curr);
		}
		temp = "";
		for (int i = 0; i < k / 3; i++) {
			temp += "BRG";
		}
		if (k % 3 == 1) temp += "B";
		else temp += "BR";
		for (int i = 0; i <= n - k; i++) {
			int curr = 0, x = 0;
			for (int j = i; j < i + k; j++) {
				if (s[j] != temp[x]) curr++;
				x++;
			}
			ans = min(ans, curr);
		}
		cout << ans << endl;
	}
}
