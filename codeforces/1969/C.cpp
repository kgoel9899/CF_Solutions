#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mod 998244353
#define int long long
#define setpres cout << fixed << setprecision(10)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int INF = 1e18;

#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }

int solve(int curr, int n, int k, vector<int>& v, vector<vector<int>>& dp) {
    if(curr == n) return 0;
    if(dp[curr][k] != -1) return dp[curr][k];
    int ans = v[curr] + solve(curr + 1, n, k, v, dp);
    int mn = v[curr];
    for(int i=1;i<=k;i++) {
        if(curr + i >= n) break;
        mn = min(mn, v[curr + i]);
        ans = min(ans, mn * (i + 1) + solve(curr + i + 1, n, k - i, v, dp));
    }
    return dp[curr][k] = ans;
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        cout << solve(0, n, k, v, dp) << endl;
    }
}