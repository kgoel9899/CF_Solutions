#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 998244353
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
		string s;
		cin >> s;
		priority_queue<int> pq;
		int ct = 0;
		for (auto i : s) {
			if (i == '1') ct++;
			else {
				pq.push(ct);
				ct = 0;
			}
		}
		pq.push(ct);
		int ans = 0;
		while (!pq.empty()) {
			ans += pq.top();
			pq.pop();
			if (!pq.empty()) pq.pop();
		}
		cout << ans << endl;
	}
}
