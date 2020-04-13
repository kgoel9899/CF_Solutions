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
		int board[9][9];
		for (int i = 0; i < 9; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 9; j++) {
				board[i][j] = s[j] - '0';
			}
		}
		//00, 31, 62, 13, 44, 75, 26, 57, 88
		vector<int> cg = {0, 0, 3, 1, 6, 2, 1, 3, 4, 4, 7, 5, 2, 6, 5, 7, 8, 8};
		int x = 0;
		for (int p = 0; p < 9; p++) {
			int i = cg[x], j = cg[x + 1];
			x += 2;
			if (board[i][j] == 1) {
				board[i][j] = 2;
			} else {
				board[i][j] = 1;
			}
		}
		for (int i = 0; i < 9; i++) {
			string s = "";
			for (int j = 0; j < 9; j++) {
				s += board[i][j] + '0';
			}
			cout << s << endl;
		}
	}

	return 0;
}
