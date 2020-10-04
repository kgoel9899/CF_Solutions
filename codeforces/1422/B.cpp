#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
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
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v(n, vector<int>(m));
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin >> v[i][j];
			}
		}
		int l = 0, r = m - 1;
		int up = 0, down = n - 1;
		int ct = 0;
		int ans = 0;
		int y = 0, x = 0;
		for(int j=0;j<(m+1)/2;j++) {
			int x = 0;
			for(int i=0;i<(n+1)/2;i++) {
				int a = v[0 + x][0 + y], b = v[0 + x][m - 1 - y], c = v[n - 1 - x][0 + y], d = v[n - 1 - x][m - 1 - y];
				map<int, int> mm;
				vector<int> test = {a, b, c, d};
				int mn = INT_MAX;
				for(int p=0;p<4;p++) {
					int sum = 0;
					for(int q=0;q<4;q++) {
						if(p == q) continue;
						sum += abs(test[q] - test[p]);
					}
					mn = min(mn, sum);
				}
				// mm[a]++;
				// mm[b]++;
				// mm[c]++;
				// mm[d]++;
				// map<int, int>::iterator it1 = mm.begin(), it2 = mm.begin();
				// while(it1 != mm.end()) {
				// 	it2++;
				// }
				// cout << a << " " << b << " " << c << " " << d << " ";
				// int mx = 0, num = -1;
				// for(auto i : mm) {
				// 	if(i.second > mx) {
				// 		mx = i.second;
				// 		num = i.first;
				// 	}
				// }
				// int temp = 0;
				// for(auto i : mm) {
				// 	temp += i.second * abs(i.first - num);
				// }
				int temp = mn;
				if(x == n / 2) temp /= 2;
				if(y == m / 2) temp /= 2;
				// cout << temp << endl;
				ans += temp;
				x++;
			}
			y++;
		}
		cout << ans << endl;
	}
}