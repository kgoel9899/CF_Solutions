#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 205;
int solve(vector<vector<int>>& dp, vector<int>& v, int n, int ind, int ti) {
    if(ind == n) return 0;
    if(ti >= 2 * n + 1) return INF;
    if(dp[ind][ti] != -1) return dp[ind][ti];
    int ans = solve(dp, v, n, ind, ti + 1);
    ans = min(ans, abs(v[ind] - ti) + solve(dp, v, n, ind + 1, ti + 1));
    return dp[ind][ti] = ans;
}
int32_t main() {
    int t = 1;
    cin >> t;
    while(t--) {
        vector<vector<int>> dp(N, vector<int>(2 * N, -1));
        vector<int> v(N);
        int n;
        cin >> n;
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.begin() + n);
        cout << solve(dp, v, n, 0, 1) << endl;
    }
    return 0;
}