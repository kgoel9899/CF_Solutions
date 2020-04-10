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

	int n;
	cin >> n;
	int arr[n];
	int ct = 0;
	int prod = 1;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 0) ct++;
		else {
			if (arr[i] < 0) {
				ans += abs(arr[i]) - 1;
				prod *= -1;
			} else if (arr[i] > 0) {
				ans += arr[i] - 1;
				prod *= 1;
			}
		}
	}
	if (ct > 0) ans += ct;
	else {
		if (prod != 1) ans += 2;
	}
	cout << ans << endl;
	return 0;
}
