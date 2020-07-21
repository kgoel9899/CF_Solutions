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

	int t;
	cin >> t;
	while (t--) {
		int n, mm;
		cin >> n >> mm;
		map<int, int> m1, m2;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			m1[num]++;
		}
		for (int i = 0; i < mm; i++) {
			int num;
			cin >> num;
			m2[num]++;
		}
		int flag = 0;
		for (auto i : m1) {
			if (m2[i.first] >= 1 && i.second >= 1) {
				cout << "YES" << endl;
				cout << 1 << " " << i.first << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			for (auto i : m2) {
				if (m1[i.first] >= 1 && i.second >= 1) {
					cout << "YES" << endl;
					cout << 1 << " " << i.first << endl;
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) cout << "NO" << endl;
	}

	return 0;
}
