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
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int temp = -1;
		for (int i = 0; i < n; i++) {
			if (v[i] != 1) {
				temp = i;
				break;
			}
		}
		if (temp == -1) {
			if (n % 2 == 0) cout << "Second" << endl;
			else cout << "First" << endl;
		} else {
			if (temp % 2 == 0) cout << "First" << endl;
			else cout << "Second" << endl;
		}
	}

	return 0;
}
