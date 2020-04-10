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
 
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> p(n, 0), c(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> p[i] >> c[i];
		}
		int i = 1;
		if (p[0] < c[0]) {
			cout << "NO" << endl;
			continue;
		}
		for (; i < n; i++) {
			if (p[i] < c[i]) break;
			if (p[i] < p[i - 1] || c[i] < c[i - 1]) break;
			else {
				if (c[i] >= c[i - 1]) {
					int diff = c[i] - c[i - 1];
					if (p[i] - p[i - 1] < diff) break;
				}
			}
		}
		if (i == n) cout << "YES" << endl;
		else cout << "NO" << endl;
 
	}
 
	return 0;
}