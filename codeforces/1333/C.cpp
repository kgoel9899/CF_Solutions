#include<bits/stdc++.h>
using namespace std;

#define ff                   first
#define ss                   second
#define ll                   long long
#define ld                   double
#define pb                   push_back
#define mp                   make_pair
#define MAX                  100001
#define mod                  998244353
#define inf                  1e18
#define w(x)                 int t; cin >> t; while(t--)
#define fori(i, a, b)        for(int i = a; i <= b; i++)
#define ford(i, b, a)        for(int i = b; i >= a; i--)
#define mk(arr,n,type)       type* arr = new type[n];
#define pii                  pair<int, int>
#define vi                   vector<int>
#define um                   unordered_map<int, int>
#define setbits(x)           __builtin_popcountll(x)
#define fast                 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;

	ll n;
	cin >> n;
	ll arr[n];
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll summ[n + 1];
	summ[0] = 0;
	for (ll i = 1; i <= n; i++) {
		summ[i] = summ[i - 1] + arr[i - 1];
	}
	ll start = 0, end = 0;
	set<ll> s = {0};
	ll ans = 0;
	while (start < n) {
		while (end < n && s.count(summ[end + 1]) == 0) {
			s.insert(summ[end + 1]);
			end++;
		}
		ans += end - start;
		s.erase(summ[start]);
		start++;
	}
	cout << ans << endl;
	return 0;
}
