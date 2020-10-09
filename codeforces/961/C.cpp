#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int n;
		cin >> n;
		vector<vector<string>> v(4, vector<string>(n));
		for(int i=0;i<4;i++) {
			for(int j=0;j<n;j++) {
				cin >> v[i][j];
			}
		}
		vector<int> a(4), b(4);
		for(int i=0;i<4;i++) {
			for(int j=0;j<n;j++) {
				for(int k=0;k<n;k++) {
					if((j + k) % 2 == 0) {
						a[i] += (v[i][j][k] == '1');
						b[i] += (v[i][j][k] == '0');
					} else {
						a[i] += (v[i][j][k] == '0');
						b[i] += (v[i][j][k] == '1');
					}
				}
			}
		}
		int ans1 = a[0] + a[1] + b[2] + b[3];
		int ans2 = a[0] + a[2] + b[1] + b[3];
		int ans3 = a[0] + a[3] + b[1] + b[2];
		int ans4 = b[0] + b[1] + a[2] + a[3];
		int ans5 = b[0] + b[2] + a[1] + a[3];
		int ans6 = b[0] + b[3] + a[1] + a[2];
		cout << min({ans1, ans2, ans3, ans4, ans5, ans6}) << endl;
	}
}