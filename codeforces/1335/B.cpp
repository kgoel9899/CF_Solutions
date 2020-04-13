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

	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		string s = "";
		unordered_map<char, int> hash;
		for (int i = 0; i < b; i++) {
			s += 'a' + i;
			hash['a' + i]++;
		}
		for (int i = b; i < a; i++) {
			s += 'a';
			hash['a']++;
		}
		int tot = a;
		int x = 1;
		int l = a;
		while (l < n) {
			hash[s[x - 1]]--;
			if (hash[s[x - 1]] == 0) {
				s += s[x - 1];
				hash[s[x - 1]]++;
			} else {
				s += 'a';
				hash['a']++;
			}
			x++;
			l++;
		}
		cout << s << endl;
	}

	return 0;
}
