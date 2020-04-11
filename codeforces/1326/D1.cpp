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

bool check(string s) {
	int n = s.size();
	int j = n - 1;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[j]) return false;
		j--;
	}
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fast;

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size(), ct = 0;
		string pre = "", suff = "";
		for (int i = 0, j = n - 1; i<n, j >= 0, i < j; i++, j--) {
			if (s[i] != s[j]) break;
			else {
				pre += s[i];
				suff += s[j];
				ct++;
			}
		}
		reverse(suff.begin(), suff.end());
		string temp1 = "";
		int maxi1 = 0;
		for (int i = ct; i < n - ct; i++) {
			temp1 += s[i];
			if (check(temp1)) maxi1 = i - (ct - 1);
		}
		temp1 = temp1.substr(0, maxi1);
		string temp2 = "";
		int maxi2 = 0;
		for (int i = n - 1 - ct; i >= ct; i--) {
			temp2 += s[i];
			if (check(temp2)) maxi2 = n - ct - i;
		}
		temp2 = temp2.substr(0, maxi2);
		if (maxi1 > maxi2) cout << pre + temp1 + suff << endl;
		else cout << pre + temp2 + suff << endl;
	}

	return 0;
}
