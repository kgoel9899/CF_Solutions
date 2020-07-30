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
		int n;
		cin >> n;
		// if (n == 1) cout << 8 << endl;
		// else if (n == 2) cout << 98 << endl;
		// else if (n == 3) cout << 998 << endl;
		// else {
		int m = n / 4;
		if (n % 4 == 0) m--;
		for (int i = 0; i < n - m - 1; i++) {
			cout << 9;
		}
		for (int i = 0; i < m + 1; i++) {
			cout << 8;
		}
		cout << endl;
		// }
	}
}


// #include<bits/stdc++.h>
// using namespace std;
// #define MAX 100001
// #define MOD 998244353
// #define ll long long
// #define ld long double
// #define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl "\n"
// void IO() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	fast;
// }
// int main() {
// 	IO();
// 	int t = 1;
// 	cin >> t;
// 	while (t--) {
// 		int n;
// 		cin >> n;
// 		vector<int> v = {6, 10, 14, 15, 21, 22, 26};
// 		for (int i = 0; i < 7; i++) {

// 		}
// 		vector<int> ans = {6, 10, 14};
// 		int diff = n - 30;
// 		int a = 6, b = 10, c = 14;
// 		int x = 3;
// 		while (true) {
// 			if (a + b + c >= n || x >= 7) {
// 				cout << "NO" << endl;
// 				break;
// 			}
// 			int diff = n - a - b - c;
// 			if (diff != a && diff != b && diff != c) {
// 				cout << "YES" << endl;
// 				cout << a << " " << b << " " << c << " " << diff << endl;
// 				break;
// 			}
// 			if (diff == a) {
// 				a = v[x++];
// 			} else if (diff == b) {
// 				b = v[x++];
// 			} else if (diff == c) {
// 				c = v[x++];
// 			}
// 		}
// 	}
// }
