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
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> v, temp;
		int mx = INT_MAX, tmx = INT_MAX;
		for (int i = 1; i <= y - x; i++) {
			// cout << i << endl;
			// return 0;
			if ((y - x) % i == 0) {
				v.clear();
				v.push_back(x);
				v.push_back(y);
				int ct = 2;
				for (int j = x + i; j < y; j += i) {
					v.push_back(j);
					ct++;
				}
				tmx = y;
				if (ct > n) continue;
				for (int j = x - i; j >= 1 && ct < n; j -= i) {
					v.push_back(j);
					ct++;
				}
				for (int j = y + i; ct < n; j += i) {
					v.push_back(j);
					tmx = j;
					ct++;
				}
				if (tmx < mx) {
					mx = tmx;
					temp = v;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << temp[i] << " ";
		}
		cout << endl;
	}
}
