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

	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		set<ll> s;
		ll arr[n];
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		ll flag = 0;
		for (ll i = 0; i < n; i++) {
			ll curr = arr[i];
			vector<ll> temp;
			if (curr != 0) {
				ll po = 0;
				while (curr != 1) {
					if (curr % k == 0) {
						curr /= k;
						po++;
					} else if (curr % k == 1) {
						temp.push_back(po);
						curr--;
						po = 0;
					} else {
						flag = 1;
						break;
					}
				}
				temp.push_back(po);
				ll x = temp.size();
				if (s.count(temp[0]) != 0) {
					flag = 1;
				} else {
					s.insert(temp[0]);
					for (ll j = 1; j < x; j++)  {
						temp[j] += temp[j - 1];
						if (s.count(temp[j]) != 0) {
							flag = 1;
							break;
						} else s.insert(temp[j]);
					}
				}
				if (flag == 1) break;
			}
		}
		if (flag == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}
