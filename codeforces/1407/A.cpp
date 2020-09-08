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
		int n;
		cin >> n;
		int one = 0, zero = 0;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (num == 1) one++;
			else zero++;
		}
		if (one > n / 2) {
			if (one % 2 == 1) one--;
			cout << one << endl;
			for (int i = 1; i <= one; i++) {
				cout << 1 << " ";
			}
			cout << endl;
		} else if (zero > n / 2) {
			if (zero % 2 == 1) zero--;
			cout << zero << endl;
			for (int i = 1; i <= zero; i++) {
				cout << 0 << " ";
			}
			cout << endl;
		} else {
			cout << n / 2 << endl;
			for (int i = 0; i < n / 2; i++) {
				cout << 0 << " ";
			}
			cout << endl;
		}
	}
}
