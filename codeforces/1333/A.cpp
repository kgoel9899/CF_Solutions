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
 
	w(t) {
		int n, m;
		cin >> n >> m;
		string s1 = "", s2 = "";
		for (int i = 0; i < m; i++) {
			if (i % 2) {
				s1 += 'W';
				s2 += 'B';
			} else {
				s1 += 'B';
				s2 += 'W';
			}
		}
		int flag = 0;
		if (m % 2 == 0 || n % 2 == 0) flag = 1;
		if (flag != 1) {
			for (int i = 0; i < n; i++) {
				if (i % 2) cout << s2 << endl;
				else cout << s1 << endl;
			}
		} else {
			int last = 0;
			for (int i = 0; i < n - 1; i++) {
				if (i % 2) {
					cout << s2 << endl;
					last = 2;
				} else {
					cout << s1 << endl;
					last = 1;
				}
			}
			if (last == 1) {
				s2[s2.size() - 2] = 'B';
				s2[s2.size() - 1] = 'B';
				cout << s2 << endl;
			} else {
				s1[s1.size() - 2] = 'B';
				s1[s1.size() - 1] = 'B';
				cout << s1 << endl;
			}
		}
	}
 
	return 0;
}