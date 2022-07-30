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

int solve(vector<int>& v, int n, int p, int k, int ind, vector<vector<int>>& dp) {
    if(ind >= n) return 0;
    if(p < v[ind]) return 0;
    if(dp[ind][p] != -1) return dp[ind][p];
    int op1 = 0, op2 = 0;
    op1 = 1 + solve(v, n, p - v[ind], k, ind + 1, dp);
    if(ind + k - 1 < n && v[ind + k - 1] <= p) op2 = k + solve(v, n, p - v[ind + k - 1], k, ind + k, dp);
    return dp[ind][p] = max(op1, op2);
}
int32_t main() {
    fast;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        int n, p, k;
        cin >> n >> p >> k;
        vector<int> v(n + 1);
        for(int i=1;i<=n;i++) {
            cin >> v[i];
        }
        sort(all(v));
        vector<int> dp(n + 1);
        for(int i=1;i<=k-1;i++) {
            dp[i] += v[i];
            dp[i] += dp[i - 1];
        }
        int ans = 0;
        for(int i=1;i<=n;i++) {
            if(i - k >= 0) {
                dp[i] += v[i];
                dp[i] += dp[i - k];
            }
            if(dp[i] <= p) ans = i;
        }
        cout << ans << endl;
        // vector<vector<int>> dp(n, vector<int>(p + 1, -1));
        // cout << solve(v, n, p, k, 0, dp) << endl;
    }
}