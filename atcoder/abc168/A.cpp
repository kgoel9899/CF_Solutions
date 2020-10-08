#include<bits/stdc++.h>
using namespace std;
#define mx 1000010
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		set<int> a = {2, 4, 5, 7, 9};
		set<int> b = {0, 1, 6, 8};
		set<int> c = {3};
		int n;
		cin >> n;
		if(a.count(n % 10) > 0) cout << "hon" << endl;
		else if(b.count(n % 10) > 0) cout << "pon" << endl;
		else cout << "bon" << endl;
	}
}