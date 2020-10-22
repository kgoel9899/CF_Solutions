#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
ll modexpo(ll a, ll b, ll c) {
	if(b == 0) return 1;
	if(b % 2 == 0) return modexpo((a * a) % c, b / 2, c);
	else return ((a % c) * (modexpo((a * a) % c, b / 2, c))) % c;
}
ll ans2 = 0;
void helper(vector<ll>& temp, ll curr, ll k) {
	if(curr == k + 1) {
		for(ll i=1;i<=k;i++) {
			int vis[k + 1];
			for(ll j=0;j<=k;j++) {
				vis[j] = 0;
			}
			int ind = i;
			while(ind != 1 && vis[ind] == 0) {
				vis[ind] = 1;
				ind = temp[ind];
			}
			if(ind != 1) return;
		}
		ans2++;
		return;
	}
	for(ll i=1;i<=k;i++) {
		temp[curr] = i;
		helper(temp, curr + 1, k);
	}
}
int main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		ll n, k;
		cin >> n >> k;
		ll ans1 = modexpo(n - k, n - k, MOD);
		vector<ll> temp(k + 1);
		helper(temp, 1, k);
		ll ans = (ans1 * ans2) % MOD;
		cout << ans << endl;
	}
}