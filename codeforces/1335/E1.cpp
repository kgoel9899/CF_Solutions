#include<bits/stdc++.h>
using namespace std;

#define ff                   first
#define ss                   second
#define int                   long long
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
#define out(flag)            if(flag == 1) cout << "NO" << endl; else cout << "YES" << endl;

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		map<int, vector<int>> hash;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			hash[arr[i]].push_back(i);
		}
		int maxi = INT_MIN;
		for (auto it : hash) {
			int sz = it.second.size();
			maxi = max(maxi, sz);
			if (sz == 1) continue;
			int x = 0, y = sz - 1;
			while (x < y) {
				int st = it.second[x], end = it.second[y];
				int nans = 2 * (x + 1);
				maxi = max(maxi, nans);
				for (auto it1 : hash) {
					if (it1.first != it.first) {
						int nsz = it1.second.size();
						int ct = 0;
						for (int i = 0; i < nsz; i++) {
							if (it1.second[i] > st && it1.second[i] < end) {
								ct++;
							}
						}
						maxi = max(maxi, nans + ct);
					}
				}
				x++;
				y--;
			}
		}
		cout << maxi << endl;
	}

	return 0;
}
