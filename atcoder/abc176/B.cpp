#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
	fast;
	int t = 1;
	// cin >> t;
    while(t--) {
		string s;
		cin >> s;
		ll n = s.size();
		ll ans = 0;
		for(ll i=0;i<n;i++) {
			ans += s[i] - '0';
			ans %= MOD;
		}
		if(ans % 9 == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
    }
}
