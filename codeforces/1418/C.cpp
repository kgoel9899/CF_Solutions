#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int solve(vector<int>& v, vector<int>& dp1, vector<int>& dp2, int n, int ind, int curr) {
	if(ind >= n) return 0;
	if(curr == 0 && dp1[ind] != -1) return dp1[ind];
	if(curr == 1 && dp2[ind] != -1) return dp2[ind];
	int ans1, ans2;
	int ct1 = v[ind];
	int ct2 = ct1;
	if(ind + 1 < n) ct2 += v[ind + 1];
	if(curr == 1) {
		ans1 = solve(v, dp1, dp2, n, ind + 1, 0);
		ans2 = solve(v, dp1, dp2, n, ind + 2, 0);
	} else {
		ans1 = ct1 + solve(v, dp1, dp2, n, ind + 1, 1);
		ans2 = ct2 + solve(v, dp1, dp2, n, ind + 2, 1);
	}
	if(curr == 0) return dp1[ind] = min(ans1, ans2);
	else return dp2[ind] = min(ans1, ans2);
}
int main() {
	fast;
	int t = 1;
	cin >> t;
    while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		vector<int> dp1(n, -1), dp2(n, -1);
		cout << solve(v, dp1, dp2, n, 0, 0) << endl;
    }
}
