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
#define ford(i, a, b)        for(int i = a; i >= b; i--)
#define mk(arr,n,type)       type* arr = new type[n];
#define p(type1, type2)      pair<type1, type2>
#define v(type)              vector<type>
#define m(type1, type2)      map<type1,type2>
#define setbits(x)           __builtin_popcountll(x)
#define fast                 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
int main() {
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	fast;
 
	w(t) {
		int n; cin >> n;
		int arr[n];
		int maxi = 0;
		fori(i, 0, n - 1) {
			cin >> arr[i];
			maxi = max(maxi, arr[i]);
		}
		set<int> s;
		int ct = 0;
		int pos = 0;
		fori(i, 0, maxi - 1) s.insert(arr[i]);
		int found = 0, found1 = 0;
		if (s.size() == maxi) pos = 1;
		set<int> s1;
		int nmaxi = 0;
		fori(i, maxi, n - 1) {
			s1.insert(arr[i]);
			nmaxi = max(nmaxi, arr[i]);
		}
		v(int) v;
		if (s1.size() == nmaxi && pos == 1 && n - maxi == s1.size()) {
			ct++;
			v.pb(maxi);
			v.pb(nmaxi);
		}
		s.clear();
		s1.clear();
		pos = 0;
		ford(i, n - 1, n - maxi) s.insert(arr[i]);
		if (s.size() == maxi) pos = 1;
		nmaxi = 0;
		ford(i, n - 1 - maxi, 0) {
			s1.insert(arr[i]);
			nmaxi = max(nmaxi, arr[i]);
		}
		if (s1.size() == nmaxi && pos == 1 && n - maxi == s1.size()) {
			ct++;
			if (ct == 1) {
				cout << 1 << endl;
				cout << nmaxi << " " << maxi << endl;
				continue;
			}
		}
		if (ct == 1) {
			cout << 1 << endl;
			cout << v[0] << " " << v[1] << endl;
			continue;
		}
		if (ct == 2) {
		    if(v[0] == v[1]) {
		        cout << 1 << endl;
		        cout << v[0] << " " << v[1] << endl;
		    } else {
    			cout << 2 << endl;
    			cout << v[0] << " " << v[1] << endl;
    			cout << nmaxi << " " << maxi << endl;
		    }
			continue;
		}
		if (ct == 0) {
			cout << 0 << endl;
			continue;
		}
 
	}
 
	return 0;
}