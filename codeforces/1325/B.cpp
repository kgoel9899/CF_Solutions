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
#define ford(i, b, a)        for(int i = b; i >= a; i--)
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
		int n;
		cin >> n;
		set<int> s;
		int num;
		fori(i, 0, n - 1) {
			cin >> num;
			s.insert(num);
		}
		cout << s.size() << endl;
	}

	return 0;
}