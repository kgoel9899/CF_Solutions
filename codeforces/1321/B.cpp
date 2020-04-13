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
#define out(flag)            if(flag == 1) cout << "NO" << endl; else cout << "YES" << endl;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;

	int n;
	cin >> n;
	int arr[n];
	unordered_map<int, ll> m;
	ll maxi = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i] - (i + 1)] += arr[i];
		maxi = max(maxi, m[arr[i] - (i + 1)]);
	}
	cout << maxi << endl;

	return 0;
}
