#include<bits/stdc++.h>
using namespace std;

#define ff                   first
#define ss                   second
#define ll                   long long
#define ld   				 double
#define pb                   push_back
#define mp                   make_pair
#define MAX                  10000
#define mod                  998244353
#define inf                  1e18
#define w(x)                 int t; cin >> t; while(t--)
#define for(i, a, b)         for(int i = a; i <= b; i++)
#define forr(i, a, b)		 for(int i = b; i >= a; i--)
#define mk(arr,n,type)       type* arr = new type[n];
#define p(type1, type2)      pair<t1, t2>
#define v(type)              vector<t1>
#define m(type1, type2)      map<t1,t2>
#define setbits(x)           __builtin_popcountll(x)
#define fast                 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;

	int k;
	cin >> k;
	if (k == 0) {
		cout << 1 << " " << 1 << endl;
		cout << 1 << endl;
	} else {
		cout << 3 << " " << 3 << endl;
		int a = (1 << 18) - 1, b = 1 << 17;
		cout << a << " " << a << " " << b << endl;
		cout << a << " " << k << " " << b + k << endl;
		cout << b << " " << b + k << " " << k << endl;
	}

	return 0;
}