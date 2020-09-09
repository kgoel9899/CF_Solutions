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
		int a, b;
		cin >> a >> b;
		if (a == b) cout << 0 << endl;
		else if (a > b) {
			if ((a - b) % 2 == 0) cout << 1 << endl;
			else cout << 2 << endl;
		} else {
			if ((b - a) % 2 == 1) cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
}
