#include<bits/stdc++.h>
using namespace std;
#define MAX 1000010
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int32_t main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << 2 << endl;
		if(n == 2) cout << 1 << " " << 2 << endl;
		else {
			cout << n - 2 << " " << n << endl;
			cout << n - 1 << " " << n - 1 << endl;
			for(int i=n-1;i>=3;i--) {
				cout << i - 2 << " " << i << endl;
			}
		}
	}
}