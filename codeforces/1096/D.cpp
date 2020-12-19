#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;
const int N = 1e5 + 5;
int dp[N][4];
vector<int> v(N);
int n;
string s;
string t = "hard";
int helper(int i, int j) {
    if(j >= 4) return INF;
    if(i == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] != t[j]) return dp[i][j] = helper(i + 1, j);
    else return dp[i][j] = min(helper(i + 1, j) + v[i], helper(i + 1, j + 1));
}
int32_t main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--) {
        cin >> n;
        cin >> s;
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << helper(0, 0) << endl;
    }
}