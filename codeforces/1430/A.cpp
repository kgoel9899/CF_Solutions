#include<bits/stdc++.h>
using namespace std;
#define MAX 1000010
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
	fast;
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int mx = n / 7, flag = 0;
		while(mx >= 0) {
			int mmx1 = n - mx * 7;
			int mmx = mmx1 / 5;
			while(mmx >= 0) {
				int check = n - mx * 7 - mmx * 5;
				if(check % 3 == 0) {
					flag = 1;
					cout << check / 3 << " " << mmx << " " << mx << endl;
					break;
				}
				mmx--;
			}
			if(flag == 1) break;
			mx--;
		}
		if(flag == 0) cout << -1 << endl;
	}
}