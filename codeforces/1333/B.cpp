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
 
struct node {
	int mo, z, o;
};
 
int main() {
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	fast;
 
	w(t) {
		int n;
		cin >> n;
		int a[n], b[n];
		node pre[n];
		int mo = 0, z = 0, o = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			pre[i].mo = mo;
			pre[i].z = z;
			pre[i].o = o;
			if (a[i] == -1) mo = 1;
			else if (a[i] == 0) z = 1;
			else o = 1;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		int i = n - 1;
		for (; i >= 0; i--) {
			if (a[i] == b[i]) continue;
			else if (a[i] < b[i]) {
				if (pre[i].o != 1) break;
			} else {
				if (pre[i].mo != 1) break;
			}
		}
		if (i == -1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
 
	return 0;
}