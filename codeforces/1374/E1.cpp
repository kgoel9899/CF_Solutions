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
struct node {
	int ti;
	int a;
	int b;
};
int main() {
	IO();
	int t = 1;
	// cin >> t;
	while (t--) {
		int n, kk;
		cin >> n >> kk;
		vector<int> time(n), a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> time[i] >> a[i] >> b[i];
		}
		vector<int> comm, fir, sec;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1 && b[i] == 1) comm.push_back(time[i]);
			else if (a[i] == 1) fir.push_back(time[i]);
			else if (b[i] == 1) sec.push_back(time[i]);
		}
		sort(comm.begin(), comm.end());
		sort(fir.begin(), fir.end());
		sort(sec.begin(), sec.end());
		int ans = 0;
		if (comm.size() + fir.size() < kk || comm.size() + sec.size() < kk) ans = -1;
		else {
			int ct = 0;
			int i = 0, j = 0, k = 0;
			while (i < comm.size() && j < fir.size() && k < sec.size() && ct < kk) {
				if (comm[i] <= fir[j] + sec[k]) {
					ans += comm[i];
					i++;
				} else {
					ans += fir[j] + sec[k];
					j++;
					k++;
				}
				ct++;
			}
			if (ct < kk) {
				for (; i < comm.size() && ct < kk; i++) {
					ans += comm[i];
					ct++;
				}
				if (ct < kk) {
					for (; j < fir.size() && k < sec.size() && ct < kk; j++, k++) {
						ans += fir[j] + sec[k];
						ct++;
					}
				}
			}
		}
		cout << ans << endl;
	}
}
