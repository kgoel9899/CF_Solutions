#include<bits/stdc++.h>
using namespace std;

#define ff                   first
#define ss                   second
#define ll                   long long
#define ld                   double
#define pb                   push_back
#define mp                   make_pair
#define MAX                  10000
#define mod                  998244353
#define inf                  1e18
#define w(x)                 int t; cin >> t; while(t--)
#define fori(i, a, b)        for(int i = a; i <= b; i++)
#define forr(i, a, b)        for(int i = b; i >= a; i--)
#define mk(arr,n,type)       type* arr = new type[n];
#define p(type1, type2)      pair<type1, type2>
#define v(type)              vector<type>
#define m(type1, type2)      map<type1,type2>
#define um(type1, type2)     unordered_map<type1, type2>
#define setbits(x)           __builtin_popcountll(x)
#define fast                 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;

	w(t) {
		int n, x;
		cin >> n >> x;
		int arr[n];
		m(int, int) m;
		fori(i, 0, n - 1) {
			cin >> arr[i];
			m[arr[i]] = 1;
		}
		int curr = 1;
		m(int, int)::iterator it = m.begin();
		while (it != m.end()) {
			if (it->first == curr) {
				it++;
				curr++;
			} else {
				if (x == 0) {
					curr--;
					break;
				} else {
					curr++;
					x--;
				}
			}
		}
		if (x == 0) {
			if (it != m.end()) cout << curr << endl;
			else cout << curr - 1 << endl;
		} else cout << curr + x - 1 << endl;
	}

	return 0;
}